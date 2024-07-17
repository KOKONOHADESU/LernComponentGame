#include <DxLib.h>
#include "Application.h"

// �G���g���[�|�C���g
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
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

	// �\�t�g�̏I�� 
	return 0;					
}
