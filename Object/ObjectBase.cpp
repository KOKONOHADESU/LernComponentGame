#include "ObjectBase.h"

namespace Object
{
	// コンストラクタ
	Base::Base() :
		m_isActive(true)
	{
	}

	// コンポーネントの追加
	void Base::AddComponent(std::unique_ptr<Component::Base>&& pComponent)
	{
		m_pComponentList.push_back(std::move(pComponent));
	}
}