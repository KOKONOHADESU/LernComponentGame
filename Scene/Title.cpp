#include "Title.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// コンストラクタ
	Title::Title(const std::shared_ptr<Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// デストラクタ
	Title::~Title()
	{
	}

	// 初期化
	void Title::Init()
	{
	}

	// 終了処理
	void Title::End()
	{
	}

	// 更新
	void Title::Update()
	{
	}

	// 描画
	void Title::Draw()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TitleScene");
	}
}