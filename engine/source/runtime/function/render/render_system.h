#pragma once

#include "pass/ui_pass.h"
#include "pass/base_pass.h"

#include <map>
#include <memory>
#include <functional>

namespace Bamboo
{
	class RenderSystem
	{
	public:
		void init();
		void tick(float delta_time);
		void destroy();

		std::shared_ptr<RenderPass> getRenderPass(ERenderPassType render_pass_type);

	private:
		void onCreateSwapchainObjects(const std::shared_ptr<class Event>& event);
		void onDestroySwapchainObjects(const std::shared_ptr<class Event>& event);
		void onRecordFrame(const std::shared_ptr<class Event>& event);

		void collectRenderDatas();

		std::shared_ptr<class Texture2D> m_dummy_texture;
		std::shared_ptr<UIPass> m_ui_pass;
		std::map<ERenderPassType, std::shared_ptr<RenderPass>> m_render_passes;
	};
}