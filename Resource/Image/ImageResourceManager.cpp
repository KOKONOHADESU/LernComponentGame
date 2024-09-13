#include "ImageResourceManager.h"
#include <DxLib.h>
#include <cassert>

namespace Resource
{
	// �f�X�g���N�^
	ImageManager::~ImageManager()
	{
		// �S�Ẳ摜���\�[�X���폜
		for (auto& image : m_imageTable)
		{
			image.second->Delete();
		}
		// �e�[�u�����N���A
		m_imageTable.clear();
	}

	// �摜���\�[�X��ǂݍ���
	std::unique_ptr<Image> ImageManager::Load(const std::string& filePath, const bool isEternal)
	{
		// �e�[�u���̒��Ɋ��ɓǂݍ���ł���摜���\�[�X���m�F
		if (m_imageTable.find(filePath) == m_imageTable.end())
		{
			// �Ȃ��ꍇ
			
			// �񓯊��ǂݍ��ݐݒ�ɕύX
			SetUseASyncLoadFlag(true);

			// �摜���\�[�X��ǂݍ���
			auto handle = LoadGraph(filePath.c_str());

			// �����ǂݍ��ݐݒ�ɕύX
			SetUseASyncLoadFlag(false);

			// �C���X�^���X�𐶐����A�e�[�u���ɕۑ�
			m_imageTable[filePath] = std::make_unique<Image>(handle, filePath, isEternal);
		}

		// �Q�ƃJ�E���g�𑝂₷
		m_imageTable[filePath]->AddReferenceCount();

		// �Ăяo�����̃N���X���폜���ꂽ�ꍇ�A�ꏏ�ɍ폜����ăf�X�g���N�^���Ăяo���Ăق����ׁA
		// �C���X�^���X�𐶐����ĕԂ�
		return std::make_unique<Image>(m_imageTable[filePath]->GetHandle(), filePath, isEternal);
	}

	// �񓯊��ǂݍ��݂̃n���h�����m�F���A�ǂݍ��݂��������Ă���ꍇ�̓n���h�������������m�F����
	void ImageManager::CheckAsyncLoadHandle()
	{
		// �񓯊��ǂݍ��݂��������Ă��邩�`�F�b�N
		for (auto& image : m_imageTable)
		{
			// �t�@�C���p�X���Ԉ���Ă���ꍇ��-1���Ԃ����ׁA
			// �{���̎g�p�p�r�͈Ⴄ�����̊֐��Ŋm�F����
			int result = CheckHandleASyncLoad(image.second->GetHandle());
			assert(result != -1);
		}
	}

	// ���\�[�X�̎Q�Ƃ̐����m�F���A�Q�Ƃ��Ȃ��ꍇ�̓��\�[�X���������
	void ImageManager::Delete(const std::string& filePath)
	{
		// �e�[�u���̒��Ɋ��ɓǂݍ���ł���摜���\�[�X���m�F
		if (m_imageTable.find(filePath) == m_imageTable.end())
		{
			// �Ȃ��ꍇ�͉������Ȃ�
			return;
		}

		// �i�v�t���O�������Ă���ꍇ�́A������Ȃ�
		if (m_imageTable[filePath]->IsEternal())
		{
			return;
		}

		// �Q�ƃJ�E���g�����炷
		m_imageTable[filePath]->SubReferenceCount();

		// �Q�ƃJ�E���g��0�ȉ��ɂȂ����ꍇ�́A���\�[�X�����
		if (m_imageTable[filePath]->GetReferenceCount() <= 0)
		{
			// ���\�[�X�����
			m_imageTable[filePath]->Delete();

			// �e�[�u������폜
			m_imageTable.erase(filePath);
		}
	}
}