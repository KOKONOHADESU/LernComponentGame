#pragma once
#include "SceneBase.h"

/// <summary>
/// �e�X�g�V�[��
/// </summary>
class TestScene : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
	TestScene(const std::shared_ptr<SceneManager>& manager);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TestScene();

	/// <summary>
	/// ������
	/// </summary>
	void Init() override final;

	/// <summary>
	/// �I������
	/// </summary>
	void End() override final;

	/// <summary>
	/// �X�V
	/// </summary>
	void Update() override final;

	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override final;
};