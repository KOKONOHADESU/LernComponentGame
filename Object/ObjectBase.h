#pragma once
#include <vector>
#include <memory>
#include "../Component/ComponentBase.h"

namespace Object
{
	/// <summary>
	/// �I�u�W�F�N�g�̊��N���X
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
		virtual ~Base();

		/// <summary>
		/// ������
		/// </summary>
		virtual void Init() = 0;

		/// <summary>
		/// �I������
		/// </summary>
		virtual void End() = 0;

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		virtual void Draw() = 0;

		/// <summary>
		/// �A�N�e�B�u��Ԃ�ݒ肷��
		/// </summary>
		/// <param name="isActive">�A�N�e�B�u��ԃt���O</param>
		void SetActive(const bool isActive) { m_isActive = isActive; }

		/// <summary>
		/// �A�N�e�B�u��Ԃ��擾����
		/// </summary>
		/// <returns>�A�N�e�B�u���</returns>
		bool IsActive() const { return m_isActive; }

		/// <summary>
		/// �w�肳�ꂽ�^�̃R���|�[�l���g���擾����
		/// </summary>
		/// <typeparam name="T">�R���|�[�l���g�̌^</typeparam>
		/// <returns>�R���|�[�l���g</returns>
		template<class T> 
		T* GetComponent()
		{
			for (auto& component : m_pComponentList)
			{
				// �R���|�[�l���g��T�^�ɃL���X�g
				auto castedComponent = dynamic_cast<T*>(component.get()));

				// �L���X�g�ɐ��������ꍇ�͂��̃R���|�[�l���g��return
				if (castedComponent)
				{
					return castedComponent;
				}
			}	
			// ���Y�R���|�[�l���g���Ȃ����nullptr��return
			return nullptr;
		}

	protected:
		/// <summary>
		/// �R���|�[�l���g��ǉ�����
		/// ���L�������̃N���X�ŏ��L�������ׁA�E�Ӓl�Q�ƂŎ󂯎��
		/// </summary>
		/// <param name="component">�R���|�[�l���g�̉E�Ӓl</param>
		void AddComponent(std::unique_ptr<Component::Base>&& pComponent);

		template<class T> 
		T* AddComponent()
		{
			// �R���|�[�l���g�𐶐�
			auto pComponent = std::make_unique<T>();

			// �R���|�[�l���g��ǉ�
			AddComponent(std::move(pComponent));

			// �R���|�[�l���g��return
			return pComponent.get();
		}

	protected:
		// �R���|�[�l���g���X�g
		std::vector<std::unique_ptr<Component::Base>> m_pComponentList;

		// �A�N�e�B�u���
		// ��A�N�e�B�u��Ԃ̏ꍇ�͍X�V�����A�`�揈�����s��Ȃ�
		bool m_isActive;
	};
}