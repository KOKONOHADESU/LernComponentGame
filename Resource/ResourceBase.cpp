#include "ResourceBase.h"

namespace Resource
{
	// �R���X�g���N�^
	Base::Base() :
		m_handle(-1),
		m_referenceCount(0),
		m_isEternal(false)
	{
	}
}