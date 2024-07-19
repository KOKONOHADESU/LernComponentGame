#include "Test.h"
#include "../MyDebug/Text.h"

namespace Scene
{
	// �R���X�g���N�^
	Test::Test(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// �f�X�g���N�^
	Test::~Test()
	{
	}

	// ������
	void Test::Init()
	{
	}

	// �I������
	void Test::End()
	{
	}

	// �X�V
	void Test::Update()
	{
		// ���݂̃V�[������\��
		Debug::Text::AddLog("TestScene");
	}

	// �`��
	void Test::Draw()
	{
	}
}