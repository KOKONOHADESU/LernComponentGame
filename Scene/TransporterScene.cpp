#include "TransporterScene.h"
#include "TitleScene.h"
#include "TestScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputState.h"
#include <DxLib.h>

namespace
{
	// �\������e�L�X�g�̑S�̂̈ʒu
	const int draw_text_pos_x = 1920 / 2 - 100;
	const int draw_text_pos_y = 1080 / 2 - 100;

	// �e�L�X�g�̕�����
	constexpr int text_space_y = 32;
}


// �R���X�g���N�^
TransporterScene::TransporterScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager),
	m_selectIndex(0)
{
}

// �f�X�g���N�^
TransporterScene::~TransporterScene()
{
}

//������
void TransporterScene::Init()
{
	m_scenes[SceneItem::TITLE] = "TitleScene";
	m_scenes[SceneItem::TEST] = "TestScene";
}

// �I������
void TransporterScene::End()
{
}

// �X�V
void TransporterScene::Update()
{
	// �I�������㉺�Ő؂�ւ�
	int sceneItemTotalValue = static_cast<int>(SceneItem::MAX);
	if (InputState::IsTriggered(InputType::UP))
	{
		m_selectIndex = ((m_selectIndex - 1) + sceneItemTotalValue) % sceneItemTotalValue;
	}
	else if (InputState::IsTriggered(InputType::DOWN))
	{
		m_selectIndex = (m_selectIndex + 1) % sceneItemTotalValue;
	}

	// ����{�^���������ꂽ��V�[���J��
	if (InputState::IsTriggered(InputType::DECISION))
	{
		switch (static_cast<SceneItem>(m_selectIndex))
		{
		// �^�C�g��
		case SceneItem::TITLE:
			m_manager->ChangeScene(std::make_shared<TitleScene>(m_manager));
			return;

		// �e�X�g
		case SceneItem::TEST:
			m_manager->ChangeScene(std::make_shared<TestScene>(m_manager));
			return;
		}
	}
}

// �`��
void TransporterScene::Draw()
{
	// ���݂̃V�[������\��
	DebugText::AddLog("TransporterScene");

	for (auto& scene : m_scenes)
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
