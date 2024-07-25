#pragma once
#include "../Util/SingletonBase.h"
#include <vector>

namespace Object
{
	/// <summary>
	/// オブジェクトの管理クラス
	/// </summary>
	class Manager : public SingletonBase<Manager>
	{
	public:
		// SingletonBaseクラスでのみインスタンス生成を許可する
		friend class SingletonBase<Manager>;

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Manager() {};

	private:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Manager() {};

	private:

	};
}