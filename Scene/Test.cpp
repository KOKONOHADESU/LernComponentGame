#include "Test.h"
#include "Transporter.h"
#include "../MyDebug/Text.h"
#include "../Util/InputState.h"
#include "../Resource/ImageManager.h"
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
	Test::Test(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager)
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
		m_image = Resource::ImageManager::GetInstance()->Load(image_file_path, true);
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

		// Transporter�V�[���ɑJ��
		if (InputState::IsTriggered(InputType::BACK))
		{
			m_manager->ChangeScene(std::make_shared<Scene::Transporter>(m_manager));
		}
	}

	// �`��
	void Test::Draw()
	{
		// �摜�̕`��
		DrawRotaGraph(1920 / 2, 1080 / 2, 2.0, 0.0, m_image->GetHandle(), true);
	}
}