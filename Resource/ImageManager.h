#pragma once
#include "../Util/SingletonBase.h"
#include "Image.h"
#include <string>
#include <unordered_map>

namespace Resource
{
	/// <summary>
	/// 画像リソースの管理クラス
	/// それぞれのシーンで画像を読み込み、不要になったリソースは自動的に解放する
	/// </summary>
	class ImageManager : public SingletonBase<ImageManager>
	{
	public:
		// SingletonBaseクラスでのみインスタンス生成を許可する
		friend class SingletonBase<ImageManager>;

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ImageManager();

		/// <summary>
		/// 画像リソースを読み込む
		/// 既に読み込んでいる場合は、テーブルに保存した画像リソースインスタンスを返す
		/// 永続フラグが立っている場合は、画像リソースを永久に所持する
		/// </summary>
		/// <param name="filePath">ファイルパス</param>
		/// <param name="isEternal">画像リソースを永久に所持するか</param>
		/// <returns>テーブルに保存した画像リソースインスタンスと同じデータを持つ、インスタンスを生成して返す
		/// (呼び出し元のクラスが削除された場合、一緒に削除されてデストラクタを呼び出してほしい為)</returns>
		std::unique_ptr<Image> Load(const std::string& filePath, const bool isEternal = false);

		/// <summary>
		/// リソースの参照の数を確認し、参照がない場合はリソースを解放する
		/// </summary>
		/// <param name="filePath">ファイルパス</param>
		void Delete(const std::string& filePath);

	private:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		ImageManager() {};

	private:
		// 画像テーブル
		// first : ファイルパス
		// second : 画像リソースクラスのインスタンス
		std::unordered_map<std::string, std::unique_ptr<Image>> m_imageTable;
	};
}