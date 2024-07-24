#include "SceneManager.h"
#include "LoadScene.h"
#include <DxLib.h>

namespace Scene
{
	// コンストラクタ
	Manager::Manager() : 
		m_isLoadScene(false)
	{
	}

	// 更新
	void Manager::Update()
	{
		// リストが空っぽだったら何もしない
		if (!m_scenes.empty())
		{
			// 先頭のみ実行
			m_scenes.front()->Update();
		}
	}

	// 描画
	void Manager::Draw()
	{
		// 逆順に描画(最後に積んだものが最初に描画される)
		for (auto rit = m_scenes.rbegin(); rit != m_scenes.rend(); rit++)
		{
			// 描画
			rit->get()->Draw();
		}
	}

	// シーンの切り替え
	void Manager::ChangeScene(const std::shared_ptr<Scene::Base>& scene)
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

			// 非同期読み込みのチェック
			CheckAsyncLoad();
		}
	}

	// シーンの追加
	void Manager::PushScene(const std::shared_ptr<Scene::Base>& scene)
	{
		// シーンの追加
		m_scenes.push_front(scene);

		// シーンの初期化
		m_scenes.front()->Init();

		// 非同期読み込みのチェック
		CheckAsyncLoad();
	}

	// 一番上のシーンを削除
	void Manager::PopScene()
	{
		// シーンの終了処理
		m_scenes.front()->End();

		// シーンの削除
		m_scenes.pop_front();
	}

	// シーンの全削除
	void Manager::ClearScene()
	{
		// シーンの終了処理
		for (auto& scene : m_scenes)
		{
			scene->End();
		}

		// シーンの全削除
		m_scenes.clear();
	}

	// 非同期読み込みのチェック
	void Manager::CheckAsyncLoad()
	{
		// 非同期読み込み中の数を取得
		if (GetASyncLoadNum() > 0 && !m_isLoadScene)
		{
			// フラグを立てる
			m_isLoadScene = true;

			// 非同期読み込みがあった場合ロード画面に飛ぶ
			PushScene(std::make_shared<Scene::Load>(shared_from_this()));
		}
	}
}