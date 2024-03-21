#pragma once

#include "component.h"
#include "engine/core/math/transform.h"

namespace Bamboo
{
	enum class EProjectionType
	{
		Perspective, Orthographic
	};

	class CameraComponent : public Component
	{
	public:
		CameraComponent();
		~CameraComponent();

		glm::vec3 getPosition();
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();
		glm::mat4 getProjectionMatrix(EProjectionType projection_type);
		glm::mat4 getViewProjectionMatrix();

		glm::mat4 getViewMatrixNoTranslation();
		glm::mat4 getProjectionMatrixNoYInverted();

		std::shared_ptr<class TransformComponent> getTransformComponent() { return m_transform_component; }
		void setInput(bool mouse_right_button_pressed, bool mouse_focused);

		// projection
		EProjectionType m_projection_type;
		float m_fovy;
		float m_aspect_ratio;
		float m_near;
		float m_far;
		float m_ortho_width;

		// movement
		float m_move_speed;
		float m_turn_speed;
		float m_zoom_speed;

		// postprocessing
		float m_exposure;

	protected:
		virtual void inflate() override;
		virtual void tick(float delta_time) override;

	private:
		REGISTER_REFLECTION(Component)

		template<class Archive>
		void serialize(Archive& ar)
		{
			// component
			ar(CEREAL_NVP_("component", cereal::base_class<Component>(this)));

			// projection
			ar(CEREAL_NVP_("fovy", m_fovy));
			ar(CEREAL_NVP_("near", m_near));
			ar(CEREAL_NVP_("far", m_far));

			// movement
			ar(CEREAL_NVP_("move_speed", m_move_speed));
			ar(CEREAL_NVP_("turn_speed", m_turn_speed));
			ar(CEREAL_NVP_("zoom_speed", m_zoom_speed));

			// postprocessing
			ar(CEREAL_NVP_("exposure", m_exposure));
		}

		void onKey(const std::shared_ptr<class Event>& event);
		void onCursorPos(const std::shared_ptr<class Event>& event);
		void onScroll(const std::shared_ptr<class Event>& event);

		void updateRotation();
		glm::mat4 getProjectionMatrixYInverted(const glm::mat4& projection_matrix);

		// camera component depends a transform component
		std::shared_ptr<class TransformComponent> m_transform_component;

		glm::vec3 m_forward;
		glm::vec3 m_right;
		glm::vec3 m_up;

		bool m_move_forward = false;
		bool m_move_back = false;
		bool m_move_left = false;
		bool m_move_right = false;
		bool m_move_up = false;
		bool m_move_down = false;

		bool m_mouse_right_button_pressed = false;
		bool m_mouse_focused = false;

		double m_last_xpos = 0.0f, m_last_ypos = 0.0f;
		static float m_last_aspect_ratio;

		glm::mat4 m_view_matrix;
		glm::mat4 m_projection_matrix;
		glm::mat4 m_view_projection_matrix;

		void* m_key_event_handle;
		void* m_cursor_pos_event_handle;
		void* m_scroll_event_handle;
	};
}