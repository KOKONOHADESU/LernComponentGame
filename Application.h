#pragma once
#include "Util/SingletonBase.h"

/// <summary>
/// �A�v���P�[�V�������Ǘ�����V���O���g���N���X
/// </summary>
class Application : public SingletonBase<Application>
{
public:
	// SingletonBase�N���X�ł̂݃C���X�^���X������������
	friend class SingletonBase<Application>;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Application() {}

	/// <summary>
	/// �A�v���P�[�V�����̏�����
	/// </summary>
	/// <returns>true : �����������Afalse : ���������s</returns>
	bool Init();
	
	/// <summary>
	/// �A�v���P�[�V�����̎��s
	/// </summary>
	void Run();
	
	/// <summary>
	/// �A�v���P�[�V�������I������
	/// </summary>
	void End();

private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Application(){}
};