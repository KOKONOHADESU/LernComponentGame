#pragma once
#include "SceneBase.h"

namespace Scene
{
	/// <summary>
	/// ステージ選択シーン
	/// </summary>
	class StageSelect final : public Scene::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="manager">シーンマネージャのインスタンス</param>
		StageSelect(const std::shared_ptr<Scene::Manager>& pSceneManager);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~StageSelect();

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
	};
};