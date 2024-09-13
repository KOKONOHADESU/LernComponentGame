#include "Application.h"
#include "MyDebug/DebugText.h"
#include "Util/InputStateManager.h"
#include "Resource/Image/ImageResourceManager.h"
#include "System/Window.h"
#include "Scene/TransporterScene.h"
#include "Scene/TitleScene.h"
#include <DxLib.h>
#include <string>

namespace
{
	// fps
	constexpr int fps = 60;
}

// コンストラクタ
Application::Application() :
	m_isExit(false)
{
}

// 初期化
bool Application::Init()
{
	// ウィンドウの設定
	System::Window::GetInstance()->Init();

	// 非同期読み込み設定を変更
	SetUseASyncLoadFlag(false);

	// 垂直同期をOFFにする
	SetWaitVSyncFlag(false);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// 初期化失敗
		return false;
	}

	// デバッグテキストの初期化
	Debug::Text::Init();

	// 入力状態の初期化
	InputStateManager::Init();

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
	m_pSceneManager = std::make_shared<Scene::Manager>();

// デバッグ時
#ifdef _DEBUG
	m_pSceneManager->PushScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
// リリース時
#else
	m_pSceneManager->PushScene(std::make_shared<Scene::Title>(m_pSceneManager));
#endif

	// 異常が起きた時に終了
	while (ProcessMessage() == 0)
	{
		// 現在の時間を取得
		LONGLONG time = GetNowHiPerformanceCount();

		// 画面のクリア
		ClearDrawScreen();

		// デバッグテキストのクリア
		Debug::Text::ClearLog();

		// fpsの表示
		Debug::Text::AddLog("FPS", { static_cast<int>(GetFPS()) });

		// 画像の非同期読み込みのチェック
		Resource::ImageManager::GetInstance()->CheckAsyncLoadHandle();

		// 入力状態の更新
		InputStateManager::Update();

		// シーンの更新
		m_pSceneManager->Update();

		// シーンの描画
		m_pSceneManager->Draw();

		// デバッグテキストの描画
		Debug::Text::DrawLog();

		// 裏画面を表画面を入れ替える
		ScreenFlip();

		// ゲーム終了フラグが立っていたら終了
		if (m_isExit) break;

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

// 終了処理
void Application::End()
{
	// デバッグテキストの終了処理
	Debug::Text::End();

	// シーンを全て削除
	m_pSceneManager->ClearScene();

	// 画像リソース管理の削除
	Resource::ImageManager::GetInstance()->DeleteInstance();

	// ウィンドウの削除
	System::Window::GetInstance()->DeleteInstance();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();
}

// ゲーム終了
void Application::Exit()
{
	m_isExit = true;
}