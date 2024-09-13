#include "Application.h"
#include "MyDebug/DebugText.h"
#include "Util/InputStateManager.h"
#include "Resource/Image/ImageResourceManager.h"
#include "System/Window.h"
#include "Scene/TransporterScene.h"
#include "Scene/TitleScene.h"
#include <DxLib.h>
#include <string>

namespace
{
	// fps
	constexpr int fps = 60;
}

// �R���X�g���N�^
Application::Application() :
	m_isExit(false)
{
}

// ������
bool Application::Init()
{
	// �E�B���h�E�̐ݒ�
	System::Window::GetInstance()->Init();

	// �񓯊��ǂݍ��ݐݒ��ύX
	SetUseASyncLoadFlag(false);

	// ����������OFF�ɂ���
	SetWaitVSyncFlag(false);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// ���������s
		return false;
	}

	// �f�o�b�O�e�L�X�g�̏�����
	Debug::Text::Init();

	// ���͏�Ԃ̏�����
	InputStateManager::Init();

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
	m_pSceneManager = std::make_shared<Scene::Manager>();

// �f�o�b�O��
#ifdef _DEBUG
	m_pSceneManager->PushScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
// �����[�X��
#else
	m_pSceneManager->PushScene(std::make_shared<Scene::Title>(m_pSceneManager));
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

		// fps�̕\��
		Debug::Text::AddLog("FPS", { static_cast<int>(GetFPS()) });

		// �摜�̔񓯊��ǂݍ��݂̃`�F�b�N
		Resource::ImageManager::GetInstance()->CheckAsyncLoadHandle();

		// ���͏�Ԃ̍X�V
		InputStateManager::Update();

		// �V�[���̍X�V
		m_pSceneManager->Update();

		// �V�[���̕`��
		m_pSceneManager->Draw();

		// �f�o�b�O�e�L�X�g�̕`��
		Debug::Text::DrawLog();

		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// �Q�[���I���t���O�������Ă�����I��
		if (m_isExit) break;

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

// �I������
void Application::End()
{
	// �f�o�b�O�e�L�X�g�̏I������
	Debug::Text::End();

	// �V�[����S�č폜
	m_pSceneManager->ClearScene();

	// �摜���\�[�X�Ǘ��̍폜
	Resource::ImageManager::GetInstance()->DeleteInstance();

	// �E�B���h�E�̍폜
	System::Window::GetInstance()->DeleteInstance();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();
}

// �Q�[���I��
void Application::Exit()
{
	m_isExit = true;
}