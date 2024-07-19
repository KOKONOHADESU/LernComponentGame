#include "Window.h"
#include <DxLib.h>
#include <string>

namespace
{
	// 画面サイズ
	constexpr int window_width = 1920;
	constexpr int window_height = 1080;

	// ウィンドウタイトル
	const std::string window_title = "";

	// カラービット数
	constexpr int color_depth = 32;

	// ウィンドウをフルスクリーンにするかどうか
	constexpr bool is_window_fullscreen_mode = false;
}

namespace System
{
	// コンストラクタ
	Window::Window() :
		m_isWindowFullScreen(is_window_fullscreen_mode),
		m_windowSize({ window_width, window_height })
	{
	}

	// 初期化
	void Window::Init()
	{
		// Windowモード設定
		ChangeWindowMode(!m_isWindowFullScreen);

		// Window名設定
		SetMainWindowText(window_title.c_str());

		// 画面サイズの設定
		SetGraphMode(window_width, window_height, color_depth);

		// ゲーム中にウィンドウモードを切り替えてもグラフィックハンドルをリセットしない
		SetChangeScreenModeGraphicsSystemResetFlag(true);

		// ほかのウィンドウを選択していても動くようにする
		SetAlwaysRunFlag(true);

		// ウィンドウのサイズを変更可能にする
		SetWindowSizeChangeEnableFlag(true);
	}

	// ウィンドウをフルスクリーンにするかどうかを設定する
	void Window::SetWindowFullScreen(const bool isFullScreen)
	{
		// フラグを設定
		m_isWindowFullScreen = isFullScreen;

		// ウィンドウモード設定
		ChangeWindowMode(!m_isWindowFullScreen);
	}
}