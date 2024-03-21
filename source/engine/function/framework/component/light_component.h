#pragma once

#include "component.h"
#include "engine/core/color/color.h"

namespace Bamboo
{
	class LightComponent : public Component
	{
	public:
		LightComponent();

		glm::vec3 getColor();

		float m_intensity;
		Color3 m_color;
		bool m_cast_shadow;

	private:
		REGISTER_REFLECTION(Component)
		POLYMORPHIC_DECLARATION

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));
			ar(CEREAL_NVP_("intensity", m_intensity));
			ar(CEREAL_NVP_("color", m_color));
			ar(CEREAL_NVP_("cast_shadow", m_cast_shadow));
		}
	};
}