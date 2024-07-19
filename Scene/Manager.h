#pragma once
#include <memory>
#include <list>
#include "Base.h"

namespace Scene
{
	class Base;

	/// <summary>
	/// シーンを管理するクラス
	/// シーンの切り替えやシーンの追加など
	/// </summary>
	class Manager
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

	private:
		// シーンのリスト
		std::list<std::shared_ptr<Scene::Base>> m_scenes;
	};
}