#pragma once

#include "component.h"

namespace Bamboo
{
	enum class EColliderType
	{
		Box, Sphere, Capsule, Cylinder, Mesh
	};

	class ColliderComponent : public Component
	{
	public:
		EColliderType m_type;

		glm::vec3 m_position = glm::vec3(0.0f);
		glm::vec3 m_rotation = glm::vec3(0.0f);

	private:
		REGISTER_REFLECTION(Component)
		POLYMORPHIC_DECLARATION

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));
			ar(CEREAL_NVP_("position", m_position));
		}
	};
}