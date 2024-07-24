#pragma once
#include <map>
#include <string>
#include "SceneBase.h"

namespace Scene
{
	/// <summary>
	/// シーン間を遷移するためのクラス
	/// デバッグ機能
	/// </summary>
	class Transporter final : public Scene::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="manager">シーンマネージャーのインスタンス</param>
		Transporter(const std::shared_ptr<Scene::Manager>& manager);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Transporter();

		/// <summary>
		/// 初期化
		/// </summary>
		void Init() override final;

		/// <summary>
		/// 終了処理
		/// </summary>
		void End() override final;

		/// <summary>
		/// 更新
		/// </summary>
		void Update() override final;

		/// <summary>
		/// 描画
		/// </summary>
		void Draw() override final;

	private:
		// シーンの種類
		enum class SceneItem
		{
			TITLE,	// タイトル
			TEST,	// テスト
			LOAD,	// ロード

			MAX		// 最大数
		};

	private:
		// シーンの名前
		std::map<SceneItem, std::string> m_scenes;

		// 選択中のインデックス
		int m_selectIndex;
	};
}