#pragma once

#include "component.h"

namespace Bamboo
{
	enum class EMotionType
	{
		Static, Kinematic, Dynamic
	};

	class RigidbodyComponent : public Component
	{
	public:
		EMotionType m_motion_type = EMotionType::Dynamic;
		float m_friction = 0.2f;
		float m_restitution = 0.0f;
		float m_linear_damping = 0.05f;
		float m_angular_damping = 0.05f;
		float m_gravity_factor = 1.0f;

		uint32_t m_body_id = UINT_MAX;

	private:
		REGISTER_REFLECTION(Component)
		POLYMORPHIC_DECLARATION

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));
			ar(CEREAL_NVP_("motion_type", m_motion_type));
			ar(CEREAL_NVP_("friction", m_friction));
			ar(CEREAL_NVP_("restitution", m_restitution));
			ar(CEREAL_NVP_("linear_damping", m_linear_damping));
			ar(CEREAL_NVP_("angular_damping", m_angular_damping));
			ar(CEREAL_NVP_("gravity_factor", m_gravity_factor));
		}
	};
}