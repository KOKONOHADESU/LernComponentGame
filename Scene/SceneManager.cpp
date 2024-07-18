#include "SceneManager.h"
#include "SceneBase.h"

// コンストラクタ
SceneManager::SceneManager()
{
}

// 更新
void SceneManager::Update()
{
	// リストが空っぽだったら何もしない
	if (!m_scenes.empty())
	{
		// 先頭のみ実行
		m_scenes.front()->Update();
	}
}

// 描画
void SceneManager::Draw()
{
	// 逆順に描画(最後に積んだものが最初に描画される)
	for (auto rit = m_scenes.rbegin(); rit != m_scenes.rend(); rit++)
	{
		// 描画
		rit->get()->Draw();
	}
}

// シーンの切り替え
void SceneManager::ChangeScene(const std::shared_ptr<SceneBase>& scene)
{
	// リストが空っぽだったら入れ替えるのではなく
	if (m_scenes.empty())
	{
		// シーンの追加
		PushScene(scene);
	}
	else
	{
		// シーンの終了処理
		m_scenes.front()->End();

		// 既に１つ以上あったら先頭のものを入れ替える
		m_scenes.front() = scene;

		// シーンの初期化
		m_scenes.front()->Init();
	}
}

// シーンの追加
void SceneManager::PushScene(const std::shared_ptr<SceneBase>& scene)
{
	// シーンの追加
	m_scenes.push_front(scene);

	// シーンの初期化
	m_scenes.front()->Init();
}

// 一番上のシーンを削除
void SceneManager::PopScene()
{
	// シーンの終了処理
	m_scenes.front()->End();

	// シーンの削除
	m_scenes.pop_front();
}

// シーンの全削除
void SceneManager::ClearScene()
{
	// シーンの終了処理
	for (auto& scene : m_scenes)
	{
		scene->End();
	}

	// シーンの全削除
	m_scenes.clear();
}