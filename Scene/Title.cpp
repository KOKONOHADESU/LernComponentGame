#include "Title.h"
#include "Transporter.h"
#include "../MyDebug/Text.h"
#include "../Util/InputState.h"
#include "../Resource/ImageManager.h"
#include <DxLib.h>
#include <cassert>

namespace
{
	// テスト用の画像ファイルパス
	const std::string image_file_path = "Data/Image/Test.png";
}

namespace Scene
{
	// コンストラクタ
	Title::Title(const std::shared_ptr<Manager>& manager) :
		Scene::Base(manager)
	{
	}

	// デストラクタ
	Title::~Title()
	{
	}

	// 初期化
	void Title::Init()
	{
		// 画像の読み込み
		m_image = Resource::ImageManager::GetInstance()->Load(image_file_path);
	}

	// 終了処理
	void Title::End()
	{
	}

	// 更新
	void Title::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TitleScene");

		// Transporterシーンに遷移
		if (InputState::IsTriggered(InputType::BACK))
		{
			m_manager->ChangeScene(std::make_shared<Scene::Transporter>(m_manager));
		}
	}

	// 描画
	void Title::Draw()
	{
		// 画像の描画
		DrawRotaGraph(1920 / 2, 1080 / 2, 2.0, 0.0, m_image->GetHandle(), true);
	}
}