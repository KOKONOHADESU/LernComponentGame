#include "TestScene.h"
#include "../MyDebug/DebugText.h"

// コンストラクタ
TestScene::TestScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// デストラクタ
TestScene::~TestScene()
{
}

// 初期化
void TestScene::Init()
{
}

// 終了処理
void TestScene::End()
{
}

// 更新
void TestScene::Update()
{
}

// 描画
void TestScene::Draw()
{
	// 現在のシーン名を表示
	DebugText::AddLog("TestScene");
}