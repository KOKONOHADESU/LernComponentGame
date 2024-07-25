#include "TestScene.h"
#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include "../Resource/ImageResourceManager.h"
#include <string>
#include <DxLib.h>

namespace
{
	// �e�X�g�p�̉摜�t�@�C���p�X
	const std::string image_file_path = "Data/Image/Test.png";
}

namespace Scene
{
	// �R���X�g���N�^
	Test::Test(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Scene::Base(pSceneManager)
	{
	}

	// �f�X�g���N�^
	Test::~Test()
	{
	}

	// ������
	void Test::Init()
	{
		// �摜�̓ǂݍ���
		m_pImage = Resource::ImageManager::GetInstance()->Load(image_file_path);
	}

	// �I������
	void Test::End()
	{
	}

	// �X�V
	void Test::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("TestScene");

#ifdef _DEBUG
		// Transporter�V�[���ɑJ��
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// �`��
	void Test::Draw()
	{
		// �摜�̕`��
		DrawRotaGraph(1920 / 2, 1080 / 2, 2.0, 0.0, m_pImage->GetHandle(), true);
	}
}