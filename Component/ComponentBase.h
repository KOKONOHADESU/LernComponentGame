#pragma once
#include "../Object/ObjectBase.h"
#include <memory>

namespace Component
{
	/// <summary>
	/// �R���|�[�l���g�̊��N���X
	/// </summary>
	class Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ownerObject">���������L���Ă���I�u�W�F�N�g</param>
		Base(Object::Base& ownerObject);

		/// <summary>
		/// �f�X�g���N�^
		/// 		/// </summary>
		virtual ~Base();

	protected:
		// ���������L���Ă���I�u�W�F�N�g
		Object::Base& m_ownerObject;
	};
}