#include "TestScene.h"
#include "../MyDebug/DebugText.h"

// �R���X�g���N�^
TestScene::TestScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// �f�X�g���N�^
TestScene::~TestScene()
{
}

// ������
void TestScene::Init()
{
}

// �I������
void TestScene::End()
{
}

// �X�V
void TestScene::Update()
{
}

// �`��
void TestScene::Draw()
{
	// ���݂̃V�[������\��
	DebugText::AddLog("TestScene");
}