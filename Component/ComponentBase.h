#pragma once
#include "../Object/ObjectBase.h"
#include <memory>

namespace Component
{
	/// <summary>
	/// コンポーネントの基底クラス
	/// </summary>
	class Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ownerObject">自分を所有しているオブジェクト</param>
		Base(Object::Base& ownerObject);

		/// <summary>
		/// デストラクタ
		/// 		/// </summary>
		virtual ~Base();

	protected:
		// 自分を所有しているオブジェクト
		Object::Base& m_ownerObject;
	};
}