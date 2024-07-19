#pragma once
#include "../Util/SingletonBase.h"

namespace System
{
	/// <summary>
	/// Windowクラス
	/// </summary>
	class Window : public SingletonBase<Window>
	{
	public:
		/// <summary>
		/// ウィンドウのサイズ
		/// </summary>
		struct WindowSize
		{
			int width;
			int height;
		};

	public:
		// SingletonBaseクラスでのみインスタンス生成を許可する
		friend class SingletonBase<Window>;

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Window() {};

		/// <summary>
		/// 初期化
		/// </summary>
		void Init();

		/// <summary>
		/// ウィンドウのサイズを取得する
		/// </summary>
		/// <returns>ウィンドウのサイズ</returns>
		const WindowSize& GetWindowSize() const { return m_windowSize; }

		/// <summary>
		/// ウィンドウがフルスクリーンかどうかを取得する
		/// </summary>
		/// <returns>true : フルスクリーン、false : ウィンドウ</returns>
		bool IsWindowFullScreen() const { return m_isWindowFullScreen; }

		/// <summary>
		/// ウィンドウをフルスクリーンにするかどうかを設定する
		/// </summary>
		/// <param name="isFullScreen">true : フルスクリーン、false : ウィンドウ</param>
		void SetWindowFullScreen(const bool isFullScreen);

	private:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Window();

	private:
		// ウィンドウのサイズ
		const WindowSize m_windowSize;

		// ウィンドウがフルスクリーンかどうか
		bool m_isWindowFullScreen;
	};
}