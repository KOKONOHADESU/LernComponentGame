#include "ObjectBase.h"

namespace Object
{
	// �R���|�[�l���g�̒ǉ�
	void Base::AddComponent(std::unique_ptr<Component::Base>&& pComponent)
	{
		m_pComponentList.push_back(std::move(pComponent));
	}
}