#pragma once

#include "light_component.h"

namespace Bamboo
{
	class PointLightComponent : public LightComponent
	{
	public:
		PointLightComponent();

		float m_radius;
		float m_linear_attenuation;
		float m_quadratic_attenuation;

	private:
		REGISTER_REFLECTION(LightComponent)
		POLYMORPHIC_DECLARATION

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("light", cereal::base_class<LightComponent>(this)));
			ar(CEREAL_NVP_("radius", m_radius));
			ar(CEREAL_NVP_("linear_attenuation", m_linear_attenuation));
			ar(CEREAL_NVP_("quadratic_attenuation", m_quadratic_attenuation));
		}
	};
}