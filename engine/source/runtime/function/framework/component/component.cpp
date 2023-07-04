#include "component.h"
#include "runtime/function/framework/entity/entity.h"

namespace Bamboo
{
	
	void Component::attach(std::weak_ptr<Entity>& parent)
	{
		m_parent = parent;
	}

	void Component::dettach()
	{
		m_parent.reset();
	}

}