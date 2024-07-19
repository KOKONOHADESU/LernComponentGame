#pragma once
#include "../Util/SingletonBase.h"

namespace System
{
	/// <summary>
	/// Window�N���X
	/// </summary>
	class Window : public SingletonBase<Window>
	{
	public:
		/// <summary>
		/// �E�B���h�E�̃T�C�Y
		/// </summary>
		struct WindowSize
		{
			int width;
			int height;
		};

	public:
		// SingletonBase�N���X�ł̂݃C���X�^���X������������
		friend class SingletonBase<Window>;

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Window() {};

		/// <summary>
		/// ������
		/// </summary>
		void Init();

		/// <summary>
		/// �E�B���h�E�̃T�C�Y���擾����
		/// </summary>
		/// <returns>�E�B���h�E�̃T�C�Y</returns>
		const WindowSize& GetWindowSize() const { return m_windowSize; }

		/// <summary>
		/// �E�B���h�E���t���X�N���[�����ǂ������擾����
		/// </summary>
		/// <returns>true : �t���X�N���[���Afalse : �E�B���h�E</returns>
		bool IsWindowFullScreen() const { return m_isWindowFullScreen; }

		/// <summary>
		/// �E�B���h�E���t���X�N���[���ɂ��邩�ǂ�����ݒ肷��
		/// </summary>
		/// <param name="isFullScreen">true : �t���X�N���[���Afalse : �E�B���h�E</param>
		void SetWindowFullScreen(const bool isFullScreen);

	private:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Window();

	private:
		// �E�B���h�E�̃T�C�Y
		const WindowSize m_windowSize;

		// �E�B���h�E���t���X�N���[�����ǂ���
		bool m_isWindowFullScreen;
	};
}