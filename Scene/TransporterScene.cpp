#include "TransporterScene.h"
#include "TitleScene.h"
#include "TestScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputState.h"
#include <DxLib.h>

namespace
{
	// 表示するテキストの全体の位置
	const int draw_text_pos_x = 1920 / 2 - 100;
	const int draw_text_pos_y = 1080 / 2 - 100;

	// テキストの文字間
	constexpr int text_space_y = 32;
}


// コンストラクタ
TransporterScene::TransporterScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager),
	m_selectIndex(0)
{
}

// デストラクタ
TransporterScene::~TransporterScene()
{
}

//初期化
void TransporterScene::Init()
{
	m_scenes[SceneItem::TITLE] = "TitleScene";
	m_scenes[SceneItem::TEST] = "TestScene";
}

// 終了処理
void TransporterScene::End()
{
}

// 更新
void TransporterScene::Update()
{
	// 選択肢を上下で切り替え
	int sceneItemTotalValue = static_cast<int>(SceneItem::MAX);
	if (InputState::IsTriggered(InputType::UP))
	{
		m_selectIndex = ((m_selectIndex - 1) + sceneItemTotalValue) % sceneItemTotalValue;
	}
	else if (InputState::IsTriggered(InputType::DOWN))
	{
		m_selectIndex = (m_selectIndex + 1) % sceneItemTotalValue;
	}

	// 決定ボタンが押されたらシーン遷移
	if (InputState::IsTriggered(InputType::DECISION))
	{
		switch (static_cast<SceneItem>(m_selectIndex))
		{
		// タイトル
		case SceneItem::TITLE:
			m_manager->ChangeScene(std::make_shared<TitleScene>(m_manager));
			return;

		// テスト
		case SceneItem::TEST:
			m_manager->ChangeScene(std::make_shared<TestScene>(m_manager));
			return;
		}
	}
}

// 描画
void TransporterScene::Draw()
{
	// 現在のシーン名を表示
	DebugText::AddLog("TransporterScene");

	for (auto& scene : m_scenes)
	{
		// シーン名を表示
		DrawString(draw_text_pos_x, draw_text_pos_y + text_space_y * static_cast<int>(scene.first), scene.second.c_str(), 0xffffff, true);

		// 選択中のシーンに矢印を表示
		if (scene.first == static_cast<SceneItem>(m_selectIndex))
		{
			DrawString(draw_text_pos_x - 50, draw_text_pos_y + text_space_y * static_cast<int>(scene.first), "→", 0xffffff, true);
		}
	}
}
