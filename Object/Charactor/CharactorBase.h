#pragma once
#include "../ObjectBase.h"

namespace Object::Charactor
{
	/// <summary>
	/// �L�����N�^�[�̊��N���X
	/// </summary>
	class Base : public Object::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Base(){}

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~Base(){}

		/// <summary>
		/// ����������
		/// </summary>
		virtual void Init() override = 0;

		/// <summary>
		/// �I������
		/// </summary>
		virtual void End() override = 0;

		/// <summary>
		/// �X�V����
		/// </summary>
		virtual void Update() override = 0;

		/// <summary>
		/// �`�揈��
		/// </summary>
		virtual void Draw() override = 0;

	protected:
	};
}