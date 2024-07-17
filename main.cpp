#include <DxLib.h>
#include "Application.h"

// エントリーポイント
// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// アプリケーションのインスタンスを取得
	const auto& app = Application::GetInstance();

	// アプリケーションの初期化
	if (!app->Init())
	{
		// 初期化失敗
		return -1;
	}

	// アプリケーションの実行
	app->Run();

	// ソフトの終了 
	return 0;					
}
