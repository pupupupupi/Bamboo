#pragma once

#include "engine/resource/asset/base/mesh.h"
#include "engine/resource/asset/base/asset.h"

namespace Bamboo
{
	class SkeletalMesh : public Mesh, public Asset
	{
	public:
		virtual void inflate() override;

		std::vector<SkeletalVertex> m_vertices;

	protected:
		virtual void calcBoundingBox() override;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("mesh", cereal::base_class<Mesh>(this)));
			ar(CEREAL_NVP_("vertices", m_vertices));
		}
	};
}