#pragma once

#include "engine/resource/asset/base/sub_mesh.h"
#include "host_device.h"

struct StaticVertex
{
	glm::vec3 m_position;
	glm::vec2 m_tex_coord;
	glm::vec3 m_normal;

private:
	friend class cereal::access;
	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(CEREAL_NVP_("position", m_position));
		ar(CEREAL_NVP_("tex_coord", m_tex_coord));
		ar(CEREAL_NVP_("normal", m_normal));
	}
};

struct SkeletalVertex : public StaticVertex
{
	glm::ivec4 m_bones;
	glm::vec4 m_weights;

private:
	friend class cereal::access;
	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(CEREAL_NVP_("static_vertex", cereal::base_class<StaticVertex>(this)));
		ar(CEREAL_NVP_("bones", m_bones));
		ar(CEREAL_NVP_("weights", m_weights));
	}
};

namespace Bamboo
{
	class Mesh
	{
	public:
		virtual ~Mesh();

		std::vector<SubMesh> m_sub_meshes;
		std::vector<uint32_t> m_indices;

		VmaBuffer m_vertex_buffer;
		VmaBuffer m_index_buffer;
		
		BoundingBox m_bounding_box;

	protected:
		virtual void calcBoundingBox() = 0;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("sub_meshes", m_sub_meshes));
			ar(CEREAL_NVP_("indices", m_indices));
		}
	};
}