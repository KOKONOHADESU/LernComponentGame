#pragma once
#include <memory>

/// <summary>
/// シングルトンクラスの基底クラス
/// </summary>
template<class T>
class SingletonBase
{
public:
	/// <summary>
	/// インスタンスを取得する
	/// 初めて取得する場合はインスタンスを作成する
	/// </summary>
	/// <returns>インスタンス</returns>
	static T* GetInstance()
	{
		// インスタンスがない場合は作成する
		if (!m_instance)
		{
			// インスタンスを作成
			m_instance = new T();
		}
		// インスタンスを返す
		return m_instance;
	}

	/// <summary>
	/// インスタンスを破棄する
	/// </summary>
	static void DestroyInstance()
	{
		// インスタンスがある場合は破棄する
		if (m_instance)
		{
			// インスタンスを破棄
			delete m_instance;

			// インスタンスをnullptrにする
			m_instance = nullptr;
		}
	}

protected:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SingletonBase() {}

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~SingletonBase() {}

private:
	// コピー禁止
	SingletonBase(const SingletonBase&) = delete;

	// 代入禁止
	SingletonBase& operator=(const SingletonBase&) = delete;

	// インスタンス
	static T* m_instance;
};

template <typename T> T* SingletonBase<T>::m_instance;

//protected:
//    SingletonBase() {}
//public:
//    virtual ~SingletonBase() {}
//
//    // コピー禁止
//    SingletonBase(SingletonBase const&) = delete;
//
//    // 代入禁止
//    SingletonBase& operator=(SingletonBase const&) = delete;
//
//public:
//    static std::shared_ptr<T> GetInstance()
//    {
//        auto ret_ptr = m_instance.lock();
//        if (!ret_ptr)
//        {
//            ret_ptr = std::shared_ptr<T>(new T{});
//            m_instance = std::weak_ptr<T>(ret_ptr);
//            return ret_ptr;
//        }
//
//        return m_instance.lock();
//    }
//
//private:
//    static std::weak_ptr<T> m_instance;

//template <typename T> std::weak_ptr<T>  SingletonBase<T>::m_instance;