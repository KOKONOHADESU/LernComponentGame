#include "StageSelectScene.h"
#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"

namespace Scene
{
	// �R���X�g���N�^
	StageSelect::StageSelect(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Base(pSceneManager)
	{
	}

	// �f�X�g���N�^
	StageSelect::~StageSelect()
	{
	}

	// ������
	void StageSelect::Init()
	{
	}

	// �I������
	void StageSelect::End()
	{
	}

	// �X�V
	void StageSelect::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("StageSelectScene");

#ifdef _DEBUG
		// Transporter�V�[���ɑJ��
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// �`��
	void StageSelect::Draw()
	{
	}
}
