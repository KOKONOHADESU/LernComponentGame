#include "ObjectBase.h"

namespace Object
{
	// コンポーネントの追加
	void Base::AddComponent(std::unique_ptr<Component::Base>&& pComponent)
	{
		m_pComponentList.push_back(std::move(pComponent));
	}
}