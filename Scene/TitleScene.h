#pragma once
#include "SceneBase.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene final : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="manager">�V�[���}�l�[�W���̃C���X�^���X</param>
	TitleScene(const std::shared_ptr<SceneManager>& manager);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TitleScene();

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