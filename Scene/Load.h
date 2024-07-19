#pragma once
#include "Base.h"

/// <summary>
/// ロードシーン
/// </summary>
namespace Scene
{
	class Load final : public Scene::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="manager">シーンマネージャのインスタンス</param>
		Load(const std::shared_ptr<Scene::Manager>& manager);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Load();

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
	};
}