#include "TitleScene.h"
#include "../MyDebug/DebugText.h"

// コンストラクタ
TitleScene::TitleScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// デストラクタ
TitleScene::~TitleScene()
{
}

// 初期化
void TitleScene::Init()
{
}

// 終了処理
void TitleScene::End()
{
}

// 更新
void TitleScene::Update()
{
}

// 描画
void TitleScene::Draw()
{
	// デバッグテキスト
	DebugText::AddLog("TitleScene");
}