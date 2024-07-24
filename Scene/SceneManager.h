#pragma once
#include <memory>
#include <list>
#include "SceneBase.h"

namespace Scene
{
	// プロトタイプ宣言
	class Base;

	/// <summary>
	/// シーンを管理するクラス
	/// シーンの切り替えやシーンの追加など
	/// </summary>
	class Manager : public std::enable_shared_from_this<Manager>
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Manager();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Manager() {}

		/// <summary>
		/// シーンの更新
		/// </summary>
		void Update();

		/// <summary>
		/// シーンの描画
		/// </summary>
		void Draw();

		/// <summary>
		/// シーンの切り替え
		/// 現在のシーンを削除し、引数で渡されたシーンに切り替える
		/// </summary>
		/// <param name="nextScene">切り替えたいシーンのインスタンス</param>
		void ChangeScene(const std::shared_ptr<Scene::Base>& scene);

		/// <summary>
		/// 現在のシーンを削除せずに、引数で渡されたシーンを上に積む
		/// Updateは、一番上に積まれたシーンのみが呼ばれる
		/// </summary>
		/// <param name="scene">追加したいシーンのインスタンス</param>
		void PushScene(const std::shared_ptr<Scene::Base>& scene);

		/// <summary>
		/// 一番上に積まれたシーンを削除する
		/// </summary>
		void PopScene();

		/// <summary>
		/// シーンを全て削除する
		/// </summary>
		void ClearScene();

		/// <summary>
		/// 非同期読み込みのチェック
		/// 読み込み中の場合、ロード画面を上に積む
		/// </summary>
		void CheckAsyncLoad();

		/// <summary>
		/// ロード画面の存在フラグの設定 
		/// </summary>
		/// <param name="flag">ロード画面の存在フラグ</param>
		void SetLoadSceneFlag(const bool flag) { m_isLoadScene = flag; }

	private:
		// シーンのリスト
		std::list<std::shared_ptr<Scene::Base>> m_scenes;

		// ロード画面が存在するか
		bool m_isLoadScene;
	};
}