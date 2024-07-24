#pragma once
#include <memory>
#include <list>
#include "SceneBase.h"

namespace Scene
{
	// �v���g�^�C�v�錾
	class Base;

	/// <summary>
	/// �V�[�����Ǘ�����N���X
	/// �V�[���̐؂�ւ���V�[���̒ǉ��Ȃ�
	/// </summary>
	class Manager : public std::enable_shared_from_this<Manager>
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Manager();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Manager() {}

		/// <summary>
		/// �V�[���̍X�V
		/// </summary>
		void Update();

		/// <summary>
		/// �V�[���̕`��
		/// </summary>
		void Draw();

		/// <summary>
		/// �V�[���̐؂�ւ�
		/// ���݂̃V�[�����폜���A�����œn���ꂽ�V�[���ɐ؂�ւ���
		/// </summary>
		/// <param name="nextScene">�؂�ւ������V�[���̃C���X�^���X</param>
		void ChangeScene(const std::shared_ptr<Scene::Base>& scene);

		/// <summary>
		/// ���݂̃V�[�����폜�����ɁA�����œn���ꂽ�V�[������ɐς�
		/// Update�́A��ԏ�ɐς܂ꂽ�V�[���݂̂��Ă΂��
		/// </summary>
		/// <param name="scene">�ǉ��������V�[���̃C���X�^���X</param>
		void PushScene(const std::shared_ptr<Scene::Base>& scene);

		/// <summary>
		/// ��ԏ�ɐς܂ꂽ�V�[�����폜����
		/// </summary>
		void PopScene();

		/// <summary>
		/// �V�[����S�č폜����
		/// </summary>
		void ClearScene();

		/// <summary>
		/// �񓯊��ǂݍ��݂̃`�F�b�N
		/// �ǂݍ��ݒ��̏ꍇ�A���[�h��ʂ���ɐς�
		/// </summary>
		void CheckAsyncLoad();

		/// <summary>
		/// ���[�h��ʂ̑��݃t���O�̐ݒ� 
		/// </summary>
		/// <param name="flag">���[�h��ʂ̑��݃t���O</param>
		void SetLoadSceneFlag(const bool flag) { m_isLoadScene = flag; }

	private:
		// �V�[���̃��X�g
		std::list<std::shared_ptr<Scene::Base>> m_scenes;

		// ���[�h��ʂ����݂��邩
		bool m_isLoadScene;
	};
}