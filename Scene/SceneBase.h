#pragma once
#include <memory>
#include "SceneManager.h"

// プロトタイプ宣言
class SceneManager;

/// <summary>
/// シーンの基底クラス
/// </summary>
class SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="manager">シーンマネージャのインスタンス</param>
	SceneBase(const std::shared_ptr<SceneManager>& manager) :
		m_manager(manager)
	{
	}

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~SceneBase(){}

	/// <summary>
	/// 初期化
	/// コンストラクタでは好きな場所で初期化を行えないため作成
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// 終了処理
	/// デストラクタでは好きな場所で終了処理を行えないため作成
	/// </summary>
	virtual void End() = 0;

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;

protected:
	// シーンのマネージャー
	std::shared_ptr<SceneManager> m_manager;
};