#pragma once
#include "ResourceBase.h"

namespace Resource
{
	/// <summary>
	/// �摜���\�[�X�N���X
	/// </summary>
	class Image : public Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="handle">�摜���\�[�X</param>
		/// <param name="filePath">�t�@�C���p�X</param>
		/// <param name="isEternal">�i�����t���O</param>
		Image(const int handle, const std::string& filePath, const bool isEternal);
		
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Image();

		/// <summary>
		/// ���\�[�X�̍폜
		/// </summary>
		void Delete() override;
	};
}