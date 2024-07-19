#include "Load.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// コンストラクタ
	Load::Load(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// デストラクタ
	Load::~Load()
	{
	}

	// 初期化
	void Load::Init()
	{
	}

	// 終了処理
	void Load::End()
	{
	}

	// 更新
	void Load::Update()
	{
	}

	// 描画
	void Load::Draw()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("LoadScene");
	}
}