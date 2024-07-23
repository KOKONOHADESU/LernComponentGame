#include <DxLib.h>
#include <crtdbg.h>
#include "Application.h"

// エントリーポイント
// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
#ifdef _DEBUG
	// メモリリークの確認
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// リークが発生しているメモリ確保回数を引数にすることで、
	// その個所にデバッグブレークをかけてくれる
//	_CrtSetBreakAlloc(136);
#endif

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

	// アプリケーションの終了処理
	app->End();

	// アプリケーションの解放
	app->DeleteInstance();

	// ソフトの終了 
	return 0;					
}
