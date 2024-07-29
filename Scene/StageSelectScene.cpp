#include "StageSelectScene.h"
#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"

namespace Scene
{
	// コンストラクタ
	StageSelect::StageSelect(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Base(pSceneManager)
	{
	}

	// デストラクタ
	StageSelect::~StageSelect()
	{
	}

	// 初期化
	void StageSelect::Init()
	{
	}

	// 終了処理
	void StageSelect::End()
	{
	}

	// 更新
	void StageSelect::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("StageSelectScene");

#ifdef _DEBUG
		// Transporterシーンに遷移
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// 描画
	void StageSelect::Draw()
	{
	}
}
