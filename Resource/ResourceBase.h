#pragma once
#include <string>

namespace Resource
{
	/// <summary>
	/// リソースの基底クラス
	/// </summary>
	class Base
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Base();
		
		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Base() {}

		/// <summary>
		/// リソースを解放する
		/// リソースの解放の方法はそれぞれ違うため、継承先で実装する
		/// </summary>
		virtual void Delete() = 0;

		/// <summary>
		/// リソースの参照カウントをインクリメントする
		/// </summary>
		void AddReferenceCount() { m_referenceCount++; }

		/// <summary>
		/// リソースの参照カウントをデクリメントする
		/// </summary>
		void SubReferenceCount() { m_referenceCount--; }

		/// <summary>
		/// リソースの参照カウントを取得する
		/// </summary>
		/// <returns>リソースの参照カウント</returns>
		int GetReferenceCount() const { return m_referenceCount; }

		/// <summary>
		/// リソースが永続化されているかを取得する
		/// </summary>
		/// <returns>永続化されているか</returns>
		bool IsEternal() const { return m_isEternal; }

		/// <summary>
		/// リソースのハンドルを取得する
		/// </summary>
		/// <returns>リソースのハンドル</returns>
		int GetHandle() const { return m_handle; }

	protected:
		// リソースのハンドル
		int m_handle;

		// 参照カウンタ
		// 参照カウンタが0になったらリソースを解放する
		int m_referenceCount;

		// ファイルパス
		std::string m_filePath;

		// 永続化フラグ
		bool m_isEternal;
	};
}