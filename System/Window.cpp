#include "Window.h"
#include <DxLib.h>
#include <string>

namespace
{
	// ��ʃT�C�Y
	constexpr int window_width = 1920;
	constexpr int window_height = 1080;

	// �E�B���h�E�^�C�g��
	const std::string window_title = "";

	// �J���[�r�b�g��
	constexpr int color_depth = 32;

	// �E�B���h�E���t���X�N���[���ɂ��邩�ǂ���
	constexpr bool is_window_fullscreen_mode = false;
}

namespace System
{
	// �R���X�g���N�^
	Window::Window() :
		m_isWindowFullScreen(is_window_fullscreen_mode),
		m_windowSize({ window_width, window_height })
	{
	}

	// ������
	void Window::Init()
	{
		// Window���[�h�ݒ�
		ChangeWindowMode(!m_isWindowFullScreen);

		// Window���ݒ�
		SetMainWindowText(window_title.c_str());

		// ��ʃT�C�Y�̐ݒ�
		SetGraphMode(window_width, window_height, color_depth);

		// �Q�[�����ɃE�B���h�E���[�h��؂�ւ��Ă��O���t�B�b�N�n���h�������Z�b�g���Ȃ�
		SetChangeScreenModeGraphicsSystemResetFlag(true);

		// �ق��̃E�B���h�E��I�����Ă��Ă������悤�ɂ���
		SetAlwaysRunFlag(true);

		// �E�B���h�E�̃T�C�Y��ύX�\�ɂ���
		SetWindowSizeChangeEnableFlag(true);
	}

	// �E�B���h�E���t���X�N���[���ɂ��邩�ǂ�����ݒ肷��
	void Window::SetWindowFullScreen(const bool isFullScreen)
	{
		// �t���O��ݒ�
		m_isWindowFullScreen = isFullScreen;

		// �E�B���h�E���[�h�ݒ�
		ChangeWindowMode(!m_isWindowFullScreen);
	}
}