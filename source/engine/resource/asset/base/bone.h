#pragma once

#include "engine/core/math/transform.h"
#include "engine/resource/asset/base/asset.h"

#define INVALID_BONE_INDEX 255

namespace Bamboo
{
	class Bone
	{
	public:
		std::string m_name;
		uint8_t m_parent = INVALID_BONE_INDEX;
		std::vector<uint8_t> m_children;

		QTransform m_local_bind_pose_transform;
		glm::mat4 m_global_inverse_bind_pose_matrix;
		glm::mat4 m_global_bind_pose_matrix;

		void setRotation(const glm::quat& quat);
		void setTranslation(const glm::vec3& translation);
		void setScale(const glm::vec3& scale);

		// update bone matrix
		void update(const glm::mat4& parent_global_bind_pose_matrix);

		// get bone to world matrix of this bone
		glm::mat4 matrix() const;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("name", m_name));
			ar(CEREAL_NVP_("parent", m_parent));
			ar(CEREAL_NVP_("children", m_children));
			ar(CEREAL_NVP_("local_bind_pose_transform", m_local_bind_pose_transform));
			ar(CEREAL_NVP_("global_inverse_bind_pose_matrix", m_global_inverse_bind_pose_matrix));
		}
	};
}