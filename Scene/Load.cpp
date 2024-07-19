#include "Load.h"
#include "../MyDebug/Text.h"
#include <DxLib.h>

namespace
{
	// ���[�h��ʂ��\�������Œ᎞��
	// ���[�h��ʂ���u�����\�������̂�h������
	constexpr int lowest_time_load_scene = 120;
}

namespace Scene
{
	// �R���X�g���N�^
	Load::Load(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager),
		m_time(0)
	{
	}

	// �f�X�g���N�^
	Load::~Load()
	{
	}

	// ������
	void Load::Init()
	{
	}

	// �I������
	void Load::End()
	{
	}

	// �X�V
	void Load::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("LoadScene");

		// �񓯊���ǂݍ��݂��s���Ă��Ȃ��A
		// ���[�h��ʂ��\�������Œ᎞�Ԃ��߂�����
		// ���[�h��ʂ��폜
		if (GetASyncLoadNum() <= 0 && 
			m_time++ >= lowest_time_load_scene)
		{
			m_manager->PopScene();
		}
	}

	// �`��
	void Load::Draw()
	{
		DrawBox(0, 0, 1920, 1080, 0x000000, true);
	}
}