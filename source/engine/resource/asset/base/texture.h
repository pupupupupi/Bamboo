#pragma once

#include "engine/core/vulkan/vulkan_util.h"
#include <cereal/access.hpp>

enum class ETextureType
{
	BaseColor, MetallicRoughnessOcclusion, Normal, Emissive, Cube, UI, Data
};

enum class EPixelType
{
	RGBA8, RGBA16, RGBA32, RG16, R16, R32
};

namespace Bamboo
{
	class Texture
	{
	public:
		Texture();
		virtual ~Texture();

		uint32_t m_width, m_height;
		VkFilter m_min_filter, m_mag_filter;
		VkSamplerAddressMode m_address_mode_u, m_address_mode_v, m_address_mode_w;
		ETextureType m_texture_type;
		EPixelType m_pixel_type;

		uint32_t m_mip_levels;
		uint32_t m_layers;
		VmaImageViewSampler m_image_view_sampler;

		std::vector<uint8_t> m_image_data;

		void setAddressMode(VkSamplerAddressMode address_mode);

	protected:
		bool isSRGB();
		bool isMipmap();
		VkFormat getFormat();
		void uploadKtxTexture(void* p_ktx_texture, VkFormat format = VK_FORMAT_UNDEFINED);

	private:
		friend class cereal::access;
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP_("width", m_width));
			ar(CEREAL_NVP_("height", m_height));
			ar(CEREAL_NVP_("min_filter", m_min_filter));
			ar(CEREAL_NVP_("mag_filter", m_mag_filter));
			ar(CEREAL_NVP_("address_mode_u", m_address_mode_u));
			ar(CEREAL_NVP_("address_mode_v", m_address_mode_v));
			ar(CEREAL_NVP_("address_mode_w", m_address_mode_w));
			ar(CEREAL_NVP_("texture_type", m_texture_type));
			ar(CEREAL_NVP_("pixel_type", m_pixel_type));
			ar(CEREAL_NVP_("image_data", m_image_data));
		}
	};
}