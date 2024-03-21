#pragma once

#include "component.h"
#include "engine/resource/asset/skeletal_mesh.h"

namespace Bamboo
{
	class SkeletalMeshComponent : public Component, public IAssetRef
	{
	public:
		void setSkeletalMesh(std::shared_ptr<SkeletalMesh>& skeletal_mesh);
		std::shared_ptr<SkeletalMesh> getSkeletalMesh() { return m_skeletal_mesh; }

	private:
		REGISTER_REFLECTION(Component)

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));
			ar(CEREAL_NVP_("asset_ref", cereal::base_class<IAssetRef>(this)));
		}

		virtual void bindRefs() override;

		std::shared_ptr<SkeletalMesh> m_skeletal_mesh;
	};
}