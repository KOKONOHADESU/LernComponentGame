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
		if (!m_pSceneTable.empty())
		{
			// �擪�̂ݎ��s
			m_pSceneTable.front()->Update();
		}
	}

	// �`��
	void Manager::Draw()
	{
		// �t���ɕ`��(�Ō�ɐς񂾂��̂��ŏ��ɕ`�悳���)
		for (auto rit = m_pSceneTable.rbegin(); rit != m_pSceneTable.rend(); rit++)
		{
			// �`��
			rit->get()->Draw();
		}
	}

	// �V�[���̐؂�ւ�
	void Manager::ChangeScene(const std::shared_ptr<Scene::Base>& pScene)
	{
		// ���X�g������ۂ����������ւ���̂ł͂Ȃ�
		if (m_pSceneTable.empty())
		{
			// �V�[���̒ǉ�
			PushScene(pScene);
		}
		else
		{
			// �V�[���̏I������
			m_pSceneTable.front()->End();

			// ���ɂP�ȏ゠������擪�̂��̂����ւ���
			m_pSceneTable.front() = pScene;

			// �V�[���̏�����
			m_pSceneTable.front()->Init();

			// �񓯊��ǂݍ��݂̃`�F�b�N
			CheckAsyncLoad();
		}
	}

	// �V�[���̒ǉ�
	void Manager::PushScene(const std::shared_ptr<Scene::Base>& pScene)
	{
		// �V�[���̒ǉ�
		m_pSceneTable.push_front(pScene);

		// �V�[���̏�����
		m_pSceneTable.front()->Init();

		// �񓯊��ǂݍ��݂̃`�F�b�N
		CheckAsyncLoad();
	}

	// ��ԏ�̃V�[�����폜
	void Manager::PopScene()
	{
		// �V�[���̏I������
		m_pSceneTable.front()->End();

		// �V�[���̍폜
		m_pSceneTable.pop_front();
	}

	// �V�[���̑S�폜
	void Manager::ClearScene()
	{
		// �V�[���̏I������
		for (auto& scene : m_pSceneTable)
		{
			scene->End();
		}

		// �V�[���̑S�폜
		m_pSceneTable.clear();
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