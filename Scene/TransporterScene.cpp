#include "TransporterScene.h"
#include "TitleScene.h"
#include "TestScene.h"
#include "LoadScene.h"
#include "StageSelectScene.h"
#include "../Application.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include <DxLib.h>
#include <cassert>

namespace
{
	// �\������e�L�X�g�̑S�̂̈ʒu
	const int draw_text_pos_x = 1920 / 2 - 100;
	const int draw_text_pos_y = 1080 / 2 - 100;

	// �e�L�X�g�̕�����
	constexpr int text_space_y = 32;
}

namespace Scene
{
	// �R���X�g���N�^
	Transporter::Transporter(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Base(pSceneManager),
		m_selectIndex(0)
	{
	}

	// �f�X�g���N�^
	Transporter::~Transporter()
	{
	}

	//������
	void Transporter::Init()
	{
		// �V�[������ݒ�
		m_pSceneTable[SceneItem::TITLE] = "TitleScene";
		m_pSceneTable[SceneItem::STAGE_SELECT] = "StageSelectScene";
		m_pSceneTable[SceneItem::TEST] = "TestScene";
		m_pSceneTable[SceneItem::LOAD] = "LoadScene";
		m_pSceneTable[SceneItem::EXIT] = "Exit";
	}

	// �I������
	void Transporter::End()
	{
	}

	// �X�V
	void Transporter::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("TransporterScene");

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
				// �^�C�g��
			case SceneItem::TITLE:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::Title>(m_pSceneManager));
				return;

				// �X�e�[�W�I��
			case SceneItem::STAGE_SELECT:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::StageSelect>(m_pSceneManager));
				return;

				// �e�X�g
			case SceneItem::TEST:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::Test>(m_pSceneManager));
				return;

				// ���[�h
			case SceneItem::LOAD:
				m_pSceneManager->PushScene(std::make_shared<Scene::Load>(m_pSceneManager, true));
				return;

				// �I��
			case SceneItem::EXIT:
				Application::GetInstance()->End();
				return;
			}
		}
	}

	// �`��
	void Transporter::Draw()
	{
		for (auto& scene : m_pSceneTable)
		{
			// �V�[������\��
			DrawString(draw_text_pos_x, draw_text_pos_y + text_space_y * static_cast<int>(scene.first), scene.second.c_str(), 0xffffff, true);

			// �I�𒆂̃V�[���ɖ���\��
			if (scene.first == static_cast<SceneItem>(m_selectIndex))
			{
				DrawString(draw_text_pos_x - 50, draw_text_pos_y + text_space_y * static_cast<int>(scene.first), "��", 0xffffff, true);
			}
		}
	}
}