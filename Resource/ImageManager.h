#pragma once
#include "../Util/SingletonBase.h"

// TODO: 画像管理クラスの実装
// それぞれのシーンで画像を読み込み、不要になったリソースは自動的に解放する
// https://qiita.com/tsuchinokoman/items/a01fdce36592bfc8149f
namespace Resource
{
	/// <summary>
	/// 画像管理クラス
	/// </summary>
	class ImageManager : public SingletonBase<ImageManager>
	{
	public:
		// SingletonBaseクラスでのみインスタンス生成を許可する
		friend class SingletonBase<ImageManager>;

	private:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		ImageManager() {};
	};
}