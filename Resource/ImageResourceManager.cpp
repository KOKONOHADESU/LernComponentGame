#include "ImageResourceManager.h"
#include <DxLib.h>
#include <cassert>

namespace Resource
{
	// デストラクタ
	ImageManager::~ImageManager()
	{
		// 全ての画像リソースを削除
		for (auto& image : m_imageTable)
		{
			image.second->Delete();
		}
		// テーブルをクリア
		m_imageTable.clear();
	}

	// 画像リソースを読み込む
	std::unique_ptr<Image> ImageManager::Load(const std::string& filePath, const bool isEternal)
	{
		// テーブルの中に既に読み込んでいる画像リソースか確認
		if (m_imageTable.find(filePath) == m_imageTable.end())
		{
			// ない場合

			// 画像リソースを読み込む
			auto handle = LoadGraph(filePath.c_str());
			assert(handle != -1);
			if (handle == -1) 	return nullptr;

			// インスタンスを生成し、テーブルに保存
			m_imageTable[filePath] = std::make_unique<Image>(handle, filePath, isEternal);
		}

		// 参照カウントを増やす
		m_imageTable[filePath]->AddReferenceCount();

		// 呼び出し元のクラスが削除された場合、一緒に削除されてデストラクタを呼び出してほしい為、
		// インスタンスを生成して返す
		return std::make_unique<Image>(m_imageTable[filePath]->GetHandle(), filePath, isEternal);
	}

	// リソースの参照の数を確認し、参照がない場合はリソースを解放する
	void ImageManager::Delete(const std::string& filePath)
	{
		// テーブルの中に既に読み込んでいる画像リソースか確認
		if (m_imageTable.find(filePath) == m_imageTable.end())
		{
			// ない場合は何もしない
			return;
		}

		// 永久フラグが立っている場合は、解放しない
		if (m_imageTable[filePath]->IsEternal())
		{
			return;
		}

		// 参照カウントを減らす
		m_imageTable[filePath]->SubReferenceCount();

		// 参照カウントが0以下になった場合は、リソースを解放
		if (m_imageTable[filePath]->GetReferenceCount() <= 0)
		{
			// リソースを解放
			m_imageTable[filePath]->Delete();

			// テーブルから削除
			m_imageTable.erase(filePath);
		}
	}
}