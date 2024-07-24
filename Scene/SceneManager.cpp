#include "SceneManager.h"
#include "LoadScene.h"
#include <DxLib.h>

namespace Scene
{
	// �R���X�g���N�^
	Manager::Manager() : 
		m_isLoadScene(false)
	{
	}

	// �X�V
	void Manager::Update()
	{
		// ���X�g������ۂ������牽�����Ȃ�
		if (!m_scenes.empty())
		{
			// �擪�̂ݎ��s
			m_scenes.front()->Update();
		}
	}

	// �`��
	void Manager::Draw()
	{
		// �t���ɕ`��(�Ō�ɐς񂾂��̂��ŏ��ɕ`�悳���)
		for (auto rit = m_scenes.rbegin(); rit != m_scenes.rend(); rit++)
		{
			// �`��
			rit->get()->Draw();
		}
	}

	// �V�[���̐؂�ւ�
	void Manager::ChangeScene(const std::shared_ptr<Scene::Base>& scene)
	{
		// ���X�g������ۂ����������ւ���̂ł͂Ȃ�
		if (m_scenes.empty())
		{
			// �V�[���̒ǉ�
			PushScene(scene);
		}
		else
		{
			// �V�[���̏I������
			m_scenes.front()->End();

			// ���ɂP�ȏ゠������擪�̂��̂����ւ���
			m_scenes.front() = scene;

			// �V�[���̏�����
			m_scenes.front()->Init();

			// �񓯊��ǂݍ��݂̃`�F�b�N
			CheckAsyncLoad();
		}
	}

	// �V�[���̒ǉ�
	void Manager::PushScene(const std::shared_ptr<Scene::Base>& scene)
	{
		// �V�[���̒ǉ�
		m_scenes.push_front(scene);

		// �V�[���̏�����
		m_scenes.front()->Init();

		// �񓯊��ǂݍ��݂̃`�F�b�N
		CheckAsyncLoad();
	}

	// ��ԏ�̃V�[�����폜
	void Manager::PopScene()
	{
		// �V�[���̏I������
		m_scenes.front()->End();

		// �V�[���̍폜
		m_scenes.pop_front();
	}

	// �V�[���̑S�폜
	void Manager::ClearScene()
	{
		// �V�[���̏I������
		for (auto& scene : m_scenes)
		{
			scene->End();
		}

		// �V�[���̑S�폜
		m_scenes.clear();
	}

	// �񓯊��ǂݍ��݂̃`�F�b�N
	void Manager::CheckAsyncLoad()
	{
		// �񓯊��ǂݍ��ݒ��̐����擾
		if (GetASyncLoadNum() > 0 && !m_isLoadScene)
		{
			// �t���O�𗧂Ă�
			m_isLoadScene = true;

			// �񓯊��ǂݍ��݂��������ꍇ���[�h��ʂɔ��
			PushScene(std::make_shared<Scene::Load>(shared_from_this()));
		}
	}
}