#include "SceneManager.h"
#include "SceneBase.h"

// �R���X�g���N�^
SceneManager::SceneManager()
{
}

// �X�V
void SceneManager::Update()
{
	// ���X�g������ۂ������牽�����Ȃ�
	if (!m_scenes.empty())
	{
		// �擪�̂ݎ��s
		m_scenes.front()->Update();
	}
}

// �`��
void SceneManager::Draw()
{
	// �t���ɕ`��(�Ō�ɐς񂾂��̂��ŏ��ɕ`�悳���)
	for (auto rit = m_scenes.rbegin(); rit != m_scenes.rend(); rit++)
	{
		// �`��
		rit->get()->Draw();
	}
}

// �V�[���̐؂�ւ�
void SceneManager::ChangeScene(const std::shared_ptr<SceneBase>& scene)
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
	}
}

// �V�[���̒ǉ�
void SceneManager::PushScene(const std::shared_ptr<SceneBase>& scene)
{
	// �V�[���̒ǉ�
	m_scenes.push_front(scene);

	// �V�[���̏�����
	m_scenes.front()->Init();
}

// ��ԏ�̃V�[�����폜
void SceneManager::PopScene()
{
	// �V�[���̏I������
	m_scenes.front()->End();

	// �V�[���̍폜
	m_scenes.pop_front();
}

// �V�[���̑S�폜
void SceneManager::ClearScene()
{
	// �V�[���̏I������
	for (auto& scene : m_scenes)
	{
		scene->End();
	}

	// �V�[���̑S�폜
	m_scenes.clear();
}