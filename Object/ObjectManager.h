#pragma once
#include "../Util/SingletonBase.h"
#include <vector>

namespace Object
{
	/// <summary>
	/// �I�u�W�F�N�g�̊Ǘ��N���X
	/// </summary>
	class Manager : public SingletonBase<Manager>
	{
	public:
		// SingletonBase�N���X�ł̂݃C���X�^���X������������
		friend class SingletonBase<Manager>;

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Manager() {};

	private:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Manager() {};

	private:

	};
}