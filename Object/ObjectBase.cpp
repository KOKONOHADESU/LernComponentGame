#include "ObjectBase.h"

namespace Object
{
	// �R���X�g���N�^
	Base::Base() :
		m_isActive(true)
	{
	}

	// �R���|�[�l���g�̒ǉ�
	void Base::AddComponent(std::unique_ptr<Component::Base>&& pComponent)
	{
		m_pComponentList.push_back(std::move(pComponent));
	}
}