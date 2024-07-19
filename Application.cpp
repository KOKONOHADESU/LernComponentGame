#include "Application.h"
#include "MyDebug/Text.h"
#include "Util/InputState.h"
#include "System/Window.h"
#include "Scene/Transporter.h"
#include "Scene/Title.h"
#include <DxLib.h>
#include <string>

namespace
{
	// fps
	constexpr int fps = 60;
}


// ������
bool Application::Init()
{
	// �E�B���h�E�̐ݒ�
	const auto& window = System::Window::GetInstance();
	window->Init();

	// �񓯊��ǂݍ��ݐݒ�ɕύX
	SetUseASyncLoadFlag(true);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// ���������s
		return false;
	}

	// �f�o�b�O�e�L�X�g�̏�����
	Debug::Text::Init();

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
	m_sceneManager = std::make_shared<Scene::Manager>();

// �f�o�b�O��
#ifdef _DEBUG
	m_sceneManager->PushScene(std::make_shared<Scene::Transporter>(m_sceneManager));
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
		Debug::Text::ClearLog();

		// ���͏�Ԃ̍X�V
		InputState::Update();

		// �V�[���̍X�V
		m_sceneManager->Update();

		// �V�[���̕`��
		m_sceneManager->Draw();

		// �f�o�b�O�e�L�X�g�̕`��
		Debug::Text::DrawLog();

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
	Debug::Text::End();

	// �E�B���h�E�̍폜
	const auto& window = System::Window::GetInstance();
	window->DestroyInstance();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();
}