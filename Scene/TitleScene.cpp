#include "TitleScene.h"
#include "../MyDebug/DebugText.h"

// �R���X�g���N�^
TitleScene::TitleScene(const std::shared_ptr<SceneManager>& manager) :
	SceneBase(manager)
{
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
}

// ������
void TitleScene::Init()
{
}

// �I������
void TitleScene::End()
{
}

// �X�V
void TitleScene::Update()
{
}

// �`��
void TitleScene::Draw()
{
	// �f�o�b�O�e�L�X�g
	DebugText::AddLog("TitleScene");
}