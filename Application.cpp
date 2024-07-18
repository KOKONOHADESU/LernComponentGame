#include "Application.h"
#include "MyDebug/DebugText.h"
#include "Util/InputState.h"
#include "Scene/TransporterScene.h"
#include "Scene/TitleScene.h"
#include <DxLib.h>
#include <string>

namespace
{
	// ��ʃT�C�Y
	constexpr int window_width = 1920;
	constexpr int window_height = 1080;

	// �E�B���h�E�^�C�g��
	const std::string window_title = "";

	// �J���[�r�b�g��
	constexpr int color_depth = 32;

	// �E�B���h�E���[�h
	constexpr bool window_mode = true;

	// fps
	constexpr int fps = 60;
}


// ������
bool Application::Init()
{
	// Window���[�h�ݒ�
	ChangeWindowMode(window_mode);

	// Window���ݒ�
	SetMainWindowText(window_title.c_str());

	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(window_width, window_height, color_depth);

	// �Q�[�����ɃE�B���h�E���[�h��؂�ւ��Ă��O���t�B�b�N�n���h�������Z�b�g���Ȃ�
	SetChangeScreenModeGraphicsSystemResetFlag(true);

	// �ق��̃E�B���h�E��I�����Ă��Ă������悤�ɂ���
	SetAlwaysRunFlag(true);

	// �E�B���h�E�̃T�C�Y��ύX�\�ɂ���
	SetWindowSizeChangeEnableFlag(true);

	// �񓯊��ǂݍ��ݐݒ�ɕύX
//	SetUseASyncLoadFlag(true);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// ���������s
		return false;
	}

	// �f�o�b�O�e�L�X�g�̏�����
	DebugText::Init();

	// ���͏�Ԃ̏�����
	InputState::Init();

	// �_�u���o�b�t�@���[�h
	// ����ʂɕ`��
	SetDrawScreen(DX_SCREEN_BACK);

	// ����������
	return true;
}

// ���s
void Application::Run()
{
	// �V�[���}�l�[�W���̐���
	m_sceneManager = std::make_shared<SceneManager>();

// �f�o�b�O��
#ifdef _DEBUG
	m_sceneManager->PushScene(std::make_shared<TransporterScene>(m_sceneManager));
// �����[�X��
#else
	m_sceneManager->PushScene(std::make_shared<TitleScene>(m_sceneManager));
#endif

	// �ُ킪�N�������ɏI��
	while (ProcessMessage() == 0)
	{
		// ���݂̎��Ԃ��擾
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʂ̃N���A
		ClearDrawScreen();

		// �f�o�b�O�e�L�X�g�̃N���A
		DebugText::ClearLog();

		// ���͏�Ԃ̍X�V
		InputState::Update();

		// �V�[���̍X�V
		m_sceneManager->Update();

		// �V�[���̕`��
		m_sceneManager->Draw();

		// �f�o�b�O�e�L�X�g�̕`��
		DebugText::DrawLog();

		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();

// �f�o�b�O���̂�
#ifdef _DEBUG
		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
#endif

		// fps���Œ�
		// 1/fps�b�o�߂���܂őҋ@
		// 1�b = 1000000�}�C�N���b
		// 1/fps�b = 1000000/fps�}�C�N���b
		while (GetNowHiPerformanceCount() - time < static_cast<long long>(1000000 / fps))
		{

		}
	}
}

// �I��
void Application::End()
{
	// �f�o�b�O�e�L�X�g�̏I������
	DebugText::End();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();
}