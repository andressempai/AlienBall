#include <CryEntitySystem/IEntityComponent.h>

#include <bitset>

namespace Cry::DefaultComponents {
	class CInputComponent;
	class CCharacterControllerComponent;
	class CCameraComponent;
}

class CPlayerController final : public IEntityComponent {
	struct Dimensions {
		f32 radius{};
		f32 height{};
		f32 eyes_height{};
	};

	static constexpr auto radius = 0.45f;
	static constexpr auto stand_height = 0.935f;
	static constexpr auto crouch_height = 0.535f;
	static constexpr auto capsule_height_offset = 0.5f;
	static constexpr auto eyes_height_stand = 0.735f;
	static constexpr auto eyes_height_crouch = 0.435f;
	static constexpr auto min_walk_speed = 2.5f;
	static constexpr auto max_walk_speed = 4.5f;
	static constexpr auto jump_speed = 5.7f;
	static constexpr auto rotation_pitch_min = -75.0f;
	static constexpr auto rotation_pitch_max = 80.0f;

	enum {
			idle = 0
		,	move_forward
		,	move_back
		,	move_right
		,	move_left
		,	boost
		,	jump
		,	crouch
		,	interact
		,	total_states
	};

public:
	static void ReflectType(Schematyc::CTypeDesc<CPlayerController>& desc);
	
private:
	void Initialize() override;
	Cry::Entity::EventFlags GetEventMask() const override;
	void ProcessEvent(const SEntityEvent& event) override;

	float radius_{ radius };
	float stand_height_{ stand_height };
	float crouch_height_{ crouch_height };
	float eyes_height_stand_{ eyes_height_stand };
	float eyes_height_crouch_{ eyes_height_crouch };
	float capsule_height_offset_{ capsule_height_offset };
	float min_walk_speed_{ min_walk_speed };
	float max_walk_speed_{ max_walk_speed };
	float jump_speed_{ jump_speed };
	float rotation_pitch_min_{ rotation_pitch_min };
	float rotation_pitch_max_{ rotation_pitch_max };

	Cry::DefaultComponents::CInputComponent* input_component_{};
	Cry::DefaultComponents::CCharacterControllerComponent* character_controller_component_{};
	Cry::DefaultComponents::CCameraComponent* camera_component_{};
	class CInteraction* interaction_component_{};
	class CToolBox* tool_box_component_{};

	Vec2 mouse_location_delta_{ ZERO };
	bool is_crouch_{ false };

	std::bitset<total_states> state_flags_{};

	Dimensions dimensions{ radius_, stand_height_, eyes_height_stand_ };
};