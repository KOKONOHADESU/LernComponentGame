#include "TitleScene.h"
#include "StageSelectScene.h"
#include "TransporterScene.h"
#include "../Application.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include "../Resource/ImageResourceManager.h"
#include <DxLib.h>
#include <cassert>

namespace
{
}

namespace Scene
{
	// �R���X�g���N�^
	Title::Title(const std::shared_ptr<Manager>& pSceneManager) :
		Scene::Base(pSceneManager),
		m_selectIndex(0)
	{
	}

	// �f�X�g���N�^
	Title::~Title()
	{
	}

	// ������
	void Title::Init()
	{
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

		// �I�������㉺�Ő؂�ւ�
		int sceneItemTotalValue = static_cast<int>(SceneItem::MAX);
		if (InputStateManager::IsTriggered(InputType::UP))
		{
			m_selectIndex = ((m_selectIndex - 1) + sceneItemTotalValue) % sceneItemTotalValue;
		}
		else if (InputStateManager::IsTriggered(InputType::DOWN))
		{
			m_selectIndex = (m_selectIndex + 1) % sceneItemTotalValue;
		}

		// ����{�^���������ꂽ��V�[���J��
		if (InputStateManager::IsTriggered(InputType::DECISION))
		{
			switch (static_cast<SceneItem>(m_selectIndex))
			{
				// �Q�[���X�^�[�g(�X�e�[�W�Z���N�g��ʂɑJ��)
			case SceneItem::START:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::StageSelect>(m_pSceneManager));
				return;

				// �I�v�V�������
			case SceneItem::OPTION:
			//	m_pSceneManager->ChangeScene(std::make_shared<Scene::Option>(m_pSceneManager));
				return;

				// �I��
			case SceneItem::EXIT:
				Application::GetInstance()->Exit();
				return;
			}
		}

#ifdef _DEBUG
		// Transporter�V�[���ɑJ��
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// �`��
	void Title::Draw()
	{
	}
}