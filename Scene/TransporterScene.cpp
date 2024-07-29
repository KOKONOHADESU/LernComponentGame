#include "TransporterScene.h"
#include "TitleScene.h"
#include "TestScene.h"
#include "LoadScene.h"
#include "StageSelectScene.h"
#include "../Application.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include <DxLib.h>
#include <cassert>

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
	Transporter::Transporter(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Base(pSceneManager),
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
		m_pSceneTable[SceneItem::TITLE] = "TitleScene";
		m_pSceneTable[SceneItem::STAGE_SELECT] = "StageSelectScene";
		m_pSceneTable[SceneItem::TEST] = "TestScene";
		m_pSceneTable[SceneItem::LOAD] = "LoadScene";
		m_pSceneTable[SceneItem::EXIT] = "Exit";
	}

	// 終了処理
	void Transporter::End()
	{
	}

	// 更新
	void Transporter::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TransporterScene");

		// 選択肢を上下で切り替え
		int sceneItemTotalValue = static_cast<int>(SceneItem::MAX);
		if (InputStateManager::IsTriggered(InputType::UP))
		{
			m_selectIndex = ((m_selectIndex - 1) + sceneItemTotalValue) % sceneItemTotalValue;
		}
		else if (InputStateManager::IsTriggered(InputType::DOWN))
		{
			m_selectIndex = (m_selectIndex + 1) % sceneItemTotalValue;
		}

		// 決定ボタンが押されたらシーン遷移
		if (InputStateManager::IsTriggered(InputType::DECISION))
		{
			switch (static_cast<SceneItem>(m_selectIndex))
			{
				// タイトル
			case SceneItem::TITLE:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::Title>(m_pSceneManager));
				return;

				// ステージ選択
			case SceneItem::STAGE_SELECT:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::StageSelect>(m_pSceneManager));
				return;

				// テスト
			case SceneItem::TEST:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::Test>(m_pSceneManager));
				return;

				// ロード
			case SceneItem::LOAD:
				m_pSceneManager->PushScene(std::make_shared<Scene::Load>(m_pSceneManager, true));
				return;

				// 終了
			case SceneItem::EXIT:
				Application::GetInstance()->End();
				return;
			}
		}
	}

	// 描画
	void Transporter::Draw()
	{
		for (auto& scene : m_pSceneTable)
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