#pragma once
#include "SceneBase.h"

namespace Scene
{
	/// <summary>
	/// �X�e�[�W�I���V�[��
	/// </summary>
	class StageSelect final : public Scene::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
		StageSelect(const std::shared_ptr<Scene::Manager>& pSceneManager);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~StageSelect();

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

	private:
	};
};