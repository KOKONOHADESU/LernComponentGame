#pragma once
#include "SceneBase.h"
#include "../Resource/Image/ImageResource.h"

namespace Scene
{
	/// <summary>
	/// テストシーン
	/// </summary>
	class Test : public Scene::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="manager">シーンマネージャのインスタンス</param>
		Test(const std::shared_ptr<Scene::Manager>& pSceneManager);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Test();

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
		std::unique_ptr<Resource::Image> m_pImage;
	};
}