#pragma once

#include "engine/resource/asset/material.h"
#include "engine/core/math/bounding_box.h"

namespace Bamboo
{
	class SubMesh : public IAssetRef
	{
	public:
		uint32_t m_index_offset;
		uint32_t m_index_count;
		uint32_t m_vertex_count;
		
		std::shared_ptr<Material> m_material;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("asset_ref", cereal::base_class<IAssetRef>(this)));
			ar(CEREAL_NVP_("index_offset", m_index_offset));
			ar(CEREAL_NVP_("index_count", m_index_count));
			ar(CEREAL_NVP_("vertex_count", m_vertex_count));
		}

		virtual void bindRefs() override;
	};
}