#pragma once

#include "engine/resource/asset/base/bone.h"

namespace Bamboo
{
	class Skeleton : public Asset
	{
	public:
		std::vector<Bone> m_bones;
		uint8_t m_root_bone_index;

		std::map<std::string, uint8_t> m_name_index;

		virtual void inflate() override;

		bool hasBone(const std::string& name);
		Bone* getBone(const std::string& name);
		void update();

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("name", m_name));
			ar(CEREAL_NVP_("bones", m_bones));
			ar(CEREAL_NVP_("root_bone_index", m_root_bone_index));
		}
	};
}