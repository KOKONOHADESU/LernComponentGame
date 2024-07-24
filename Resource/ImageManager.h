#pragma once
#include "../Util/SingletonBase.h"
#include "Image.h"
#include <string>
#include <unordered_map>

namespace Resource
{
	/// <summary>
	/// �摜���\�[�X�̊Ǘ��N���X
	/// ���ꂼ��̃V�[���ŉ摜��ǂݍ��݁A�s�v�ɂȂ������\�[�X�͎����I�ɉ������
	/// </summary>
	class ImageManager : public SingletonBase<ImageManager>
	{
	public:
		// SingletonBase�N���X�ł̂݃C���X�^���X������������
		friend class SingletonBase<ImageManager>;

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ImageManager();

		/// <summary>
		/// �摜���\�[�X��ǂݍ���
		/// ���ɓǂݍ���ł���ꍇ�́A�e�[�u���ɕۑ������摜���\�[�X�C���X�^���X��Ԃ�
		/// �i���t���O�������Ă���ꍇ�́A�摜���\�[�X���i�v�ɏ�������
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X</param>
		/// <param name="isEternal">�摜���\�[�X���i�v�ɏ������邩</param>
		/// <returns>�e�[�u���ɕۑ������摜���\�[�X�C���X�^���X�Ɠ����f�[�^�����A�C���X�^���X�𐶐����ĕԂ�
		/// (�Ăяo�����̃N���X���폜���ꂽ�ꍇ�A�ꏏ�ɍ폜����ăf�X�g���N�^���Ăяo���Ăق�����)</returns>
		std::unique_ptr<Image> Load(const std::string& filePath, const bool isEternal = false);

		/// <summary>
		/// ���\�[�X�̎Q�Ƃ̐����m�F���A�Q�Ƃ��Ȃ��ꍇ�̓��\�[�X���������
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X</param>
		void Delete(const std::string& filePath);

	private:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ImageManager() {};

	private:
		// �摜�e�[�u��
		// first : �t�@�C���p�X
		// second : �摜���\�[�X�N���X�̃C���X�^���X
		std::unordered_map<std::string, std::unique_ptr<Image>> m_imageTable;
	};
}