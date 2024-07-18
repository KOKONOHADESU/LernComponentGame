#pragma once
#include "SceneBase.h"

/// <summary>
/// テストシーン
/// </summary>
class TestScene : public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="manager">シーンマネージャのインスタンス</param>
	TestScene(const std::shared_ptr<SceneManager>& manager);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TestScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override final;

	/// <summary>
	/// 終了処理
	/// </summary>
	void End() override final;

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override final;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override final;
};