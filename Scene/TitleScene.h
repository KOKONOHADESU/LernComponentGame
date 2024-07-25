#pragma once
#include "SceneBase.h"
#include "../Resource/ImageResource.h"

namespace Scene
{
	/// <summary>
	/// �^�C�g���V�[��
	/// </summary>
	class Title final : public Scene::Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
		Title(const std::shared_ptr<Scene::Manager>& pSceneManager);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Title();

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
		std::unique_ptr<Resource::Image> m_pImage;
	};
}