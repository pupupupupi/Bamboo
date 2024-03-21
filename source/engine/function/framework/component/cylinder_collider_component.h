#pragma once

#include "collider_component.h"

namespace Bamboo
{
	class CylinderColliderComponent : public ColliderComponent
	{
	public:
		CylinderColliderComponent();

		float m_radius;
		float m_height;

	private:
		REGISTER_REFLECTION(ColliderComponent)

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("collider_component", cereal::base_class<ColliderComponent>(this)));
			ar(CEREAL_NVP_("radius", m_radius));
			ar(CEREAL_NVP_("height", m_height));
		}
	};
}