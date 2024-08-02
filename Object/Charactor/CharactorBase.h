#pragma once
#include "../ObjectBase.h"

namespace Object::Charactor
{
	/// <summary>
	/// キャラクターの基底クラス
	/// </summary>
	class Base : public Object::Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Base(){}

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Base(){}

		/// <summary>
		/// 初期化処理
		/// </summary>
		virtual void Init() override = 0;

		/// <summary>
		/// 終了処理
		/// </summary>
		virtual void End() override = 0;

		/// <summary>
		/// 更新処理
		/// </summary>
		virtual void Update() override = 0;

		/// <summary>
		/// 描画処理
		/// </summary>
		virtual void Draw() override = 0;

	protected:
	};
}