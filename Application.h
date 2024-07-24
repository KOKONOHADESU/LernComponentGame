#pragma once
#include <memory>
#include "Util/SingletonBase.h"
#include "Scene/SceneManager.h"

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
	~Application() {};

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

private:
	// �V�[���}�l�[�W��
	std::shared_ptr<Scene::Manager> m_sceneManager;
};