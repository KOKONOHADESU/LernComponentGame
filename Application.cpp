#include "Application.h"
#include "MyDebug/DebugText.h"
#include "Util/InputState.h"
#include "Scene/TransporterScene.h"
#include "Scene/TitleScene.h"
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

	// ウィンドウモード
	constexpr bool window_mode = true;

	// fps
	constexpr int fps = 60;
}


// 初期化
bool Application::Init()
{
	// Windowモード設定
	ChangeWindowMode(window_mode);

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

	// 非同期読み込み設定に変更
//	SetUseASyncLoadFlag(true);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// 初期化失敗
		return false;
	}

	// デバッグテキストの初期化
	DebugText::Init();

	// 入力状態の初期化
	InputState::Init();

	// ダブルバッファモード
	// 裏画面に描画
	SetDrawScreen(DX_SCREEN_BACK);

	// 初期化成功
	return true;
}

// 実行
void Application::Run()
{
	// シーンマネージャの生成
	m_sceneManager = std::make_shared<SceneManager>();

// デバッグ時
#ifdef _DEBUG
	m_sceneManager->PushScene(std::make_shared<TransporterScene>(m_sceneManager));
// リリース時
#else
	m_sceneManager->PushScene(std::make_shared<TitleScene>(m_sceneManager));
#endif

	// 異常が起きた時に終了
	while (ProcessMessage() == 0)
	{
		// 現在の時間を取得
		LONGLONG time = GetNowHiPerformanceCount();

		// 画面のクリア
		ClearDrawScreen();

		// デバッグテキストのクリア
		DebugText::ClearLog();

		// 入力状態の更新
		InputState::Update();

		// シーンの更新
		m_sceneManager->Update();

		// シーンの描画
		m_sceneManager->Draw();

		// デバッグテキストの描画
		DebugText::DrawLog();

		// 裏画面を表画面を入れ替える
		ScreenFlip();

// デバッグ時のみ
#ifdef _DEBUG
		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
#endif

		// fpsを固定
		// 1/fps秒経過するまで待機
		// 1秒 = 1000000マイクロ秒
		// 1/fps秒 = 1000000/fpsマイクロ秒
		while (GetNowHiPerformanceCount() - time < static_cast<long long>(1000000 / fps))
		{

		}
	}
}

// 終了
void Application::End()
{
	// デバッグテキストの終了処理
	DebugText::End();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();
}