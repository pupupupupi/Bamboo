#pragma once

#include "collider_component.h"

namespace Bamboo
{
	class BoxColliderComponent : public ColliderComponent
	{
	public:
		BoxColliderComponent();

		glm::vec3 m_size;

	private:
		REGISTER_REFLECTION(ColliderComponent)

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("collider_component", cereal::base_class<ColliderComponent>(this)));
			ar(CEREAL_NVP_("size", m_size));
		}
	};
}