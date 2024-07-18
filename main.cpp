#include <DxLib.h>
#include <crtdbg.h>
#include "Application.h"

// �G���g���[�|�C���g
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ���������[�N�̊m�F
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �A�v���P�[�V�����̃C���X�^���X���擾
	const auto& app = Application::GetInstance();

	// �A�v���P�[�V�����̏�����
	if (!app->Init())
	{
		// ���������s
		return -1;
	}

	// �A�v���P�[�V�����̎��s
	app->Run();

	// �A�v���P�[�V�����̏I������
	app->End();

	// �A�v���P�[�V�����̉��
	app->DestroyInstance();

	// �\�t�g�̏I�� 
	return 0;					
}
