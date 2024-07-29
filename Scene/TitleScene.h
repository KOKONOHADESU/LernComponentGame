#pragma once
#include <map>
#include "SceneBase.h"
#include "../Resource/ImageResource.h"

namespace Scene
{
	/// <summary>
	/// タイトルシーン
	/// </summary>
	class Title final : public Scene::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="manager">シーンマネージャのインスタンス</param>
		Title(const std::shared_ptr<Scene::Manager>& pSceneManager);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Title();

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
			START,			// スタート
			OPTION,			// オプション
			EXIT,			// 終了

			MAX		// 最大数
		};

	private:
		// シーンの種類と名前を紐づけているシーンのテーブル
		// first : シーンの種類
		// second : シーンの名前
		std::map<SceneItem, std::string> m_pSceneTable;

		// 選択中のインデックス
		int m_selectIndex;
	};
}