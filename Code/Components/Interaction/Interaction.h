#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/MathTypes.h>
#include <CryPhysics/physinterface.h>

class CInteraction final : public IEntityComponent {
	static constexpr auto component_update_interval = 0.25f;
	static constexpr auto distance = 1.0f;

public:
	static void ReflectType(Schematyc::CTypeDesc<CInteraction>& desc);

	[[nodiscard]] const ray_hit& hit_result() const
	{
		return hit_result_;
	}

private:
	Cry::Entity::EventFlags GetEventMask() const override;
	void ProcessEvent(const SEntityEvent& event) override;

	Schematyc::PositiveFloat component_update_interval_{ component_update_interval };
	Schematyc::PositiveFloat distance_{ distance };

	f32 time_interval_{ 0.0f };

	ray_hit hit_result_{};
};