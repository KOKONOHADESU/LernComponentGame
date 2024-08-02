#pragma once
#include "CharactorBase.h"

namespace Object::Charactor
{
	/// <summary>
	/// プレイヤークラス
	/// </summary>
	class Player final : public Object::Charactor::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Player();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Player();

		/// <summary>
		/// 初期化
		/// </summary>
		void Init() override;

		/// <summary>
		/// 終了処理
		/// </summary>
		void End() override;

		/// <summary>
		/// 更新
		/// </summary>
		void Update() override;

		/// <summary>
		/// 描画
		/// </summary>
		void Draw() override;
	};
}