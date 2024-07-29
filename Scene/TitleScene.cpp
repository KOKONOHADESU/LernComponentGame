#include "TitleScene.h"
#include "StageSelectScene.h"
#include "TransporterScene.h"
#include "../Application.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include "../Resource/ImageResourceManager.h"
#include <DxLib.h>
#include <cassert>

namespace
{
}

namespace Scene
{
	// コンストラクタ
	Title::Title(const std::shared_ptr<Manager>& pSceneManager) :
		Scene::Base(pSceneManager),
		m_selectIndex(0)
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
		// 現在のシーン名を表示
		Debug::Text::AddLog("TitleScene");

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
				// ゲームスタート(ステージセレクト画面に遷移)
			case SceneItem::START:
				m_pSceneManager->ChangeScene(std::make_shared<Scene::StageSelect>(m_pSceneManager));
				return;

				// オプション画面
			case SceneItem::OPTION:
			//	m_pSceneManager->ChangeScene(std::make_shared<Scene::Option>(m_pSceneManager));
				return;

				// 終了
			case SceneItem::EXIT:
				Application::GetInstance()->Exit();
				return;
			}
		}

#ifdef _DEBUG
		// Transporterシーンに遷移
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// 描画
	void Title::Draw()
	{
	}
}