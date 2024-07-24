#pragma once
#include <string>

namespace Resource
{
	/// <summary>
	/// ���\�[�X�̊��N���X
	/// </summary>
	class Base
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Base();
		
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~Base() {}

		/// <summary>
		/// ���\�[�X���������
		/// ���\�[�X�̉���̕��@�͂��ꂼ��Ⴄ���߁A�p����Ŏ�������
		/// </summary>
		virtual void Delete() = 0;

		/// <summary>
		/// ���\�[�X�̎Q�ƃJ�E���g���C���N�������g����
		/// </summary>
		void AddReferenceCount() { m_referenceCount++; }

		/// <summary>
		/// ���\�[�X�̎Q�ƃJ�E���g���f�N�������g����
		/// </summary>
		void SubReferenceCount() { m_referenceCount--; }

		/// <summary>
		/// ���\�[�X�̎Q�ƃJ�E���g���擾����
		/// </summary>
		/// <returns>���\�[�X�̎Q�ƃJ�E���g</returns>
		int GetReferenceCount() const { return m_referenceCount; }

		/// <summary>
		/// ���\�[�X���i��������Ă��邩���擾����
		/// </summary>
		/// <returns>�i��������Ă��邩</returns>
		bool IsEternal() const { return m_isEternal; }

		/// <summary>
		/// ���\�[�X�̃n���h�����擾����
		/// </summary>
		/// <returns>���\�[�X�̃n���h��</returns>
		int GetHandle() const { return m_handle; }

	protected:
		// ���\�[�X�̃n���h��
		int m_handle;

		// �Q�ƃJ�E���^
		// �Q�ƃJ�E���^��0�ɂȂ����烊�\�[�X���������
		int m_referenceCount;

		// �t�@�C���p�X
		std::string m_filePath;

		// �i�����t���O
		bool m_isEternal;
	};
}