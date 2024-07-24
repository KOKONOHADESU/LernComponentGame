#pragma once
#include "ResourceBase.h"

namespace Resource
{
	/// <summary>
	/// 画像リソースクラス
	/// </summary>
	class Image : public Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="handle">画像リソース</param>
		/// <param name="filePath">ファイルパス</param>
		/// <param name="isEternal">永続化フラグ</param>
		Image(const int handle, const std::string& filePath, const bool isEternal);
		
		/// <summary>
		/// デストラクタ
		/// </summary>
		~Image();

		/// <summary>
		/// リソースの削除
		/// </summary>
		void Delete() override;
	};
}