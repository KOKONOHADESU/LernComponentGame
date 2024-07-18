#pragma once
#include "SceneBase.h"

/// <summary>
/// �V�[���Ԃ�J�ڂ��邽�߂̃N���X
/// �f�o�b�O�@�\
/// </summary>
class TransporterScene final : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="manager">�V�[���}�l�[�W���[�̃C���X�^���X</param>
	TransporterScene(const std::shared_ptr<SceneManager>& manager);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TransporterScene();

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