#include "Title.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// �R���X�g���N�^
	Title::Title(const std::shared_ptr<Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// �f�X�g���N�^
	Title::~Title()
	{
	}

	// ������
	void Title::Init()
	{
	}

	// �I������
	void Title::End()
	{
	}

	// �X�V
	void Title::Update()
	{
	}

	// �`��
	void Title::Draw()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("TitleScene");
	}
}