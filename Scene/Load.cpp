#include "Load.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// �R���X�g���N�^
	Load::Load(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager)
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
	}

	// �`��
	void Load::Draw()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("LoadScene");
	}
}