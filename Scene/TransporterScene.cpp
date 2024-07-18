#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputState.h"

// コンストラクタ
TransporterScene::TransporterScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// デストラクタ
TransporterScene::~TransporterScene()
{
}

//初期化
void TransporterScene::Init()
{
}

// 終了処理
void TransporterScene::End()
{
}

// 更新
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

// 描画
void TransporterScene::Draw()
{
	DebugText::AddLog("TransporterScene");
}
