#pragma once

#include <cereal/access.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <rttr/registration>
#include <rttr/registration_friend.h>

// register all user defined serialization
namespace cereal
{
	// glm vectors serialization
	template<class Archive> void serialize(Archive& ar, glm::vec2& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y)); }
	template<class Archive> void serialize(Archive& ar, glm::vec3& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z)); }
	template<class Archive> void serialize(Archive& ar, glm::vec4& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z), CEREAL_NVP_("w", v.w)); }
	template<class Archive> void serialize(Archive& ar, glm::ivec2& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y)); }
	template<class Archive> void serialize(Archive& ar, glm::ivec3& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z)); }
	template<class Archive> void serialize(Archive& ar, glm::ivec4& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z), CEREAL_NVP_("w", v.w)); }
	template<class Archive> void serialize(Archive& ar, glm::uvec2& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y)); }
	template<class Archive> void serialize(Archive& ar, glm::uvec3& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z)); }
	template<class Archive> void serialize(Archive& ar, glm::uvec4& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z), CEREAL_NVP_("w", v.w)); }
	template<class Archive> void serialize(Archive& ar, glm::dvec2& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y)); }
	template<class Archive> void serialize(Archive& ar, glm::dvec3& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z)); }
	template<class Archive> void serialize(Archive& ar, glm::dvec4& v) { ar(CEREAL_NVP_("x", v.x), CEREAL_NVP_("y", v.y), CEREAL_NVP_("z", v.z), CEREAL_NVP_("w", v.w)); }

	// glm matrices serialization
	template<class Archive> void serialize(Archive& ar, glm::mat2& m) { ar(CEREAL_NVP_("col_0", m[0]), CEREAL_NVP_("col_1", m[1])); }
	template<class Archive> void serialize(Archive& ar, glm::dmat2& m) { ar(CEREAL_NVP_("col_0", m[0]), CEREAL_NVP_("col_1", m[1])); }
	template<class Archive> void serialize(Archive& ar, glm::mat3& m) { ar(CEREAL_NVP_("col_0", m[0]), CEREAL_NVP_("col_1", m[1]), CEREAL_NVP_("col_2", m[2])); }
	template<class Archive> void serialize(Archive& ar, glm::mat4& m) { ar(CEREAL_NVP_("col_0", m[0]), CEREAL_NVP_("col_1", m[1]), CEREAL_NVP_("col_2", m[2]), CEREAL_NVP_("col_3", m[3])); }
	template<class Archive> void serialize(Archive& ar, glm::dmat4& m) { ar(CEREAL_NVP_("col_0", m[0]), CEREAL_NVP_("col_1", m[1]), CEREAL_NVP_("col_2", m[2]), CEREAL_NVP_("col_3", m[3])); }

	template<class Archive> void serialize(Archive& ar, glm::quat& q) { ar(CEREAL_NVP_("x", q.x), CEREAL_NVP_("y", q.y), CEREAL_NVP_("z", q.z), CEREAL_NVP_("w", q.w)); }
	template<class Archive> void serialize(Archive& ar, glm::dquat& q) { ar(CEREAL_NVP_("x", q.x), CEREAL_NVP_("y", q.y), CEREAL_NVP_("z", q.z), CEREAL_NVP_("w", q.w)); }
}
