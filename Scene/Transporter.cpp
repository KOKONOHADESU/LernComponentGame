#include "Transporter.h"
#include "Title.h"
#include "Test.h"
#include "Load.h"
#include "../MyDebug/Text.h"
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

namespace Scene
{
	// コンストラクタ
	Transporter::Transporter(const std::shared_ptr<Scene::Manager>& manager) :
		Base(manager),
		m_selectIndex(0)
	{
	}

	// デストラクタ
	Transporter::~Transporter()
	{
	}

	//初期化
	void Transporter::Init()
	{
		// シーン名を設定
		m_scenes[SceneItem::TITLE] = "TitleScene";
		m_scenes[SceneItem::TEST] = "TestScene";
		m_scenes[SceneItem::LOAD] = "LoadScene";
	}

	// 終了処理
	void Transporter::End()
	{
	}

	// 更新
	void Transporter::Update()
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
				m_manager->ChangeScene(std::make_shared<Scene::Title>(m_manager));
				return;

				// テスト
			case SceneItem::TEST:
				m_manager->ChangeScene(std::make_shared<Scene::Test>(m_manager));
				return;

				// ロード
			case SceneItem::LOAD:
				m_manager->ChangeScene(std::make_shared<Scene::Load>(m_manager));
				return;
			}
		}
	}

	// 描画
	void Transporter::Draw()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TransporterScene");

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
}