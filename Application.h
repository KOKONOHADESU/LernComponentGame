#pragma once
#include "SingletonBase.h"

/// <summary>
/// アプリケーションを管理するシングルトンクラス
/// </summary>
class Application : public SingletonBase<Application>
{
public:
//	friend class SingletonBase<Application>;

	/// <summary>
	/// アプリケーションの初期化
	/// </summary>
	/// <returns>true : 初期化成功、false : 初期化失敗</returns>
	bool Init();
	
	/// <summary>
	/// アプリケーションの実行
	/// </summary>
	void Run();
	
	/// <summary>
	/// アプリケーションを終了する
	/// </summary>
	void End();

private:
};