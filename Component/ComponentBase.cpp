#include "ComponentBase.h"

namespace Component
{
	// コンストラクタ
	Base::Base(Object::Base& ownerObject) :
		m_ownerObject(ownerObject)
	{
	}
}