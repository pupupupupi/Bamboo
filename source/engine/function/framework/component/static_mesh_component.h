#pragma once

#include "component.h"
#include "engine/resource/asset/static_mesh.h"

namespace Bamboo
{
	class StaticMeshComponent : public Component, public IAssetRef
	{
	public:
		void setStaticMesh(std::shared_ptr<StaticMesh>& static_mesh);
		std::shared_ptr<StaticMesh> getStaticMesh() { return m_static_mesh; }

	private:
		REGISTER_REFLECTION(Component)

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));
			ar(CEREAL_NVP_("asset_ref", cereal::base_class<IAssetRef>(this)));
		}

		virtual void bindRefs() override;

		std::shared_ptr<StaticMesh> m_static_mesh;
	};
}