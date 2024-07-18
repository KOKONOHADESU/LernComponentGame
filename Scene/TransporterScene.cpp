#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputState.h"

// �R���X�g���N�^
TransporterScene::TransporterScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// �f�X�g���N�^
TransporterScene::~TransporterScene()
{
}

//������
void TransporterScene::Init()
{
}

// �I������
void TransporterScene::End()
{
}

// �X�V
void TransporterScene::Update()
{
	if (InputState::IsPadStick(PadLR::LEFT, PadStickInputType::UP, PadStickStrength::STRONG))
	{
		DebugText::AddLog("UP STRONG");
	}
	if (InputState::IsPadStick(PadLR::LEFT, PadStickInputType::DOWN, PadStickStrength::STRONG))
	{
		DebugText::AddLog("DOWN STRONG");
	}
	if (InputState::IsPadStick(PadLR::LEFT, PadStickInputType::LEFT, PadStickStrength::STRONG))
	{
		DebugText::AddLog("LEFT STRONG");
	}
	if (InputState::IsPadStick(PadLR::LEFT, PadStickInputType::RIGHT, PadStickStrength::STRONG))
	{
		DebugText::AddLog("RIGHT STRONG");
	}

}

// �`��
void TransporterScene::Draw()
{
	DebugText::AddLog("TransporterScene");
}
