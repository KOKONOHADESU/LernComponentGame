#pragma once
#include "Base.h"

namespace Scene
{
	/// <summary>
	/// �e�X�g�V�[��
	/// </summary>
	class Test : public Scene::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
		Test(const std::shared_ptr<Scene::Manager>& manager);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Test();

		/// <summary>
		/// ������
		/// </summary>
		void Init() override final;

		/// <summary>
		/// �I������
		/// </summary>
		void End() override final;

		/// <summary>
		/// �X�V
		/// </summary>
		void Update() override final;

		/// <summary>
		/// �`��
		/// </summary>
		void Draw() override final;
	};
}