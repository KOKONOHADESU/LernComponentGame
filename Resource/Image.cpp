#include "Image.h"
#include "ImageManager.h"
#include <DxLib.h>

namespace Resource
{
	// �R���X�g���N�^
	Image::Image(const int handle, const std::string& filePath, const bool isEternal)
	{
		m_handle = handle;
		m_filePath = filePath;
		m_isEternal = isEternal;
	}

	// �f�X�g���N�^
	Image::~Image()
	{
		ImageManager::GetInstance()->Delete(m_filePath);
	}

	// ���\�[�X�̍폜
	void Image::Delete()
	{
		DeleteGraph(m_handle);
	}
}
