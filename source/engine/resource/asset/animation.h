#pragma once

#include "engine/resource/asset/base/asset.h"

namespace Bamboo
{
	struct AnimationChannel
	{
		enum class EPathType 
		{ 
			Translation, Rotation, Scale 
		};

		EPathType m_path_type;
		std::string m_bone_name;
		uint32_t m_sampler_index;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("path_type", m_path_type));
			ar(CEREAL_NVP_("bone_name", m_bone_name));
			ar(CEREAL_NVP_("sampler_index", m_sampler_index));
		}
	};

	struct AnimationSampler
	{
		enum class EInterpolationType
		{
			Linear, Step, CubicSpline
		};

		EInterpolationType m_interp_type;
		std::vector<float> m_times;
		std::vector<glm::vec4> m_values;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("interp_type", m_interp_type));
			ar(CEREAL_NVP_("times", m_times)); 
			ar(CEREAL_NVP_("values", m_values));
		}
	};

	class Animation : public Asset
	{
	public:
		std::vector<AnimationSampler> m_samplers;
		std::vector<AnimationChannel> m_channels;

		float m_start_time;
		float m_end_time;
		float m_duration;

		virtual void inflate() override;

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("name", m_name));
			ar(CEREAL_NVP_("samplers", m_samplers)); 
			ar(CEREAL_NVP_("channels", m_channels));
		}
	};
}