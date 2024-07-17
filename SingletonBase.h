#pragma once
#include <memory>

/// <summary>
/// �V���O���g���N���X�̊��N���X
/// </summary>
template<class T>
class SingletonBase
{
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// ���߂Ď擾����ꍇ�̓C���X�^���X���쐬����
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static T* GetInstance()
	{
		// �C���X�^���X���Ȃ��ꍇ�͍쐬����
		if (!m_instance)
		{
			// �C���X�^���X���쐬
			m_instance = new T();
		}
		// �C���X�^���X��Ԃ�
		return m_instance;
	}

	/// <summary>
	/// �C���X�^���X��j������
	/// </summary>
	static void DestroyInstance()
	{
		// �C���X�^���X������ꍇ�͔j������
		if (m_instance)
		{
			// �C���X�^���X��j��
			delete m_instance;

			// �C���X�^���X��nullptr�ɂ���
			m_instance = nullptr;
		}
	}

protected:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SingletonBase() {}

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SingletonBase() {}

private:
	// �R�s�[�֎~
	SingletonBase(const SingletonBase&) = delete;

	// ����֎~
	SingletonBase& operator=(const SingletonBase&) = delete;

	// �C���X�^���X
	static T* m_instance;
};

template <typename T> T* SingletonBase<T>::m_instance;

//protected:
//    SingletonBase() {}
//public:
//    virtual ~SingletonBase() {}
//
//    // �R�s�[�֎~
//    SingletonBase(SingletonBase const&) = delete;
//
//    // ����֎~
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