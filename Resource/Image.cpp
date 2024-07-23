#include "Image.h"
#include "ImageManager.h"
#include <DxLib.h>

namespace Resource
{
	// コンストラクタ
	Image::Image(const int handle, const std::string& filePath, const bool isEternal)
	{
		m_handle = handle;
		m_filePath = filePath;
		m_isEternal = isEternal;
	}

	// デストラクタ
	Image::~Image()
	{
		ImageManager::GetInstance()->Delete(m_filePath);
	}

	// リソースの削除
	void Image::Delete()
	{
		DeleteGraph(m_handle);
	}
}
