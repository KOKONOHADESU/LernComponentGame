#pragma once
#include "CharactorBase.h"

namespace Object::Charactor
{
	/// <summary>
	/// �v���C���[�N���X
	/// </summary>
	class Player final : public Object::Charactor::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Player();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Player();

		/// <summary>
		/// ������
		/// </summary>
		void Init() override;

		/// <summary>
		/// �I������
		/// </summary>
		void End() override;

		/// <summary>
		/// �X�V
		/// </summary>
		void Update() override;

		/// <summary>
		/// �`��
		/// </summary>
		void Draw() override;
	};
}