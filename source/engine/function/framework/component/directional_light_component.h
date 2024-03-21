#pragma once

#include "light_component.h"

namespace Bamboo
{
	class DirectionalLightComponent : public LightComponent
	{
	public:
		DirectionalLightComponent();

		float m_cascade_frustum_near;

	private:
		REGISTER_REFLECTION(LightComponent)

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("light", cereal::base_class<LightComponent>(this)));
			ar(CEREAL_NVP_("cascade_frustum_near", m_cascade_frustum_near));
		}
	};
}