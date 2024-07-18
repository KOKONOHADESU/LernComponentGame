#pragma once
#include "SceneBase.h"

/// <summary>
/// シーン間を遷移するためのクラス
/// デバッグ機能
/// </summary>
class TransporterScene final : public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="manager">シーンマネージャーのインスタンス</param>
	TransporterScene(const std::shared_ptr<SceneManager>& manager);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TransporterScene();

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