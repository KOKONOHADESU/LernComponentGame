#include "Test.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// コンストラクタ
	Test::Test(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// デストラクタ
	Test::~Test()
	{
	}

	// 初期化
	void Test::Init()
	{
	}

	// 終了処理
	void Test::End()
	{
	}

	// 更新
	void Test::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TestScene");
	}

	// 描画
	void Test::Draw()
	{
	}
}