#pragma once
#include "Base.h"

/// <summary>
/// ���[�h�V�[��
/// </summary>
namespace Scene
{
	class Load final : public Scene::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
		Load(const std::shared_ptr<Scene::Manager>& manager);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Load();

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