#pragma once
#include "../Util/SingletonBase.h"

// TODO: �摜�Ǘ��N���X�̎���
// ���ꂼ��̃V�[���ŉ摜��ǂݍ��݁A�s�v�ɂȂ������\�[�X�͎����I�ɉ������
// https://qiita.com/tsuchinokoman/items/a01fdce36592bfc8149f
namespace Resource
{
	/// <summary>
	/// �摜�Ǘ��N���X
	/// </summary>
	class ImageManager : public SingletonBase<ImageManager>
	{
	public:
		// SingletonBase�N���X�ł̂݃C���X�^���X������������
		friend class SingletonBase<ImageManager>;

	private:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		ImageManager() {};
	};
}