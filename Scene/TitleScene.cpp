#include "TitleScene.h"
#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputState.h"
#include "../Resource/ImageResourceManager.h"
#include <DxLib.h>
#include <cassert>

namespace
{
	// �e�X�g�p�̉摜�t�@�C���p�X
	const std::string image_file_path = "Data/Image/Test.png";
}

namespace Scene
{
	// �R���X�g���N�^
	Title::Title(const std::shared_ptr<Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// �f�X�g���N�^
	Title::~Title()
	{
	}

	// ������
	void Title::Init()
	{
		// �摜�̓ǂݍ���
		m_image = Resource::ImageManager::GetInstance()->Load(image_file_path);
	}

	// �I������
	void Title::End()
	{
	}

	// �X�V
	void Title::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("TitleScene");

#ifdef _DEBUG
		// Transporter�V�[���ɑJ��
		if (InputState::IsTriggered(InputType::BACK))
		{
			m_manager->ChangeScene(std::make_shared<Scene::Transporter>(m_manager));
		}
#endif
	}

	// �`��
	void Title::Draw()
	{
		// �摜�̕`��
		DrawRotaGraph(1920 / 2, 1080 / 2, 2.0, 0.0, m_image->GetHandle(), true);
	}
}