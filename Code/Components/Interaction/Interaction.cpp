#include "Interaction.h"

#include <array>

void CInteraction::ReflectType(Schematyc::CTypeDesc<CInteraction>& desc)
{
	desc.SetGUID("{9753BC54-387C-4AEC-8FB5-5AE2C5F7C4FF}"_cry_guid);
	desc.SetEditorCategory("Game Components");
	desc.SetName(Schematyc::CTypeName("Interaction Component"));
	desc.SetLabel("Interaction Component");
	desc.SetDescription("Allow Entity to interact with others entities inside World.");
	desc.AddMember(
			&CInteraction::component_update_interval_
		,	'inte'
		,	"componentupdateinterval"
		,	"Component Update Interval"
		,	nullptr
		,	component_update_interval
	);

	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
	desc.AddMember(
			&CInteraction::distance_
		,	'dist'
		,	"distance"
		,	"Distance"
		,	"Interaction Distance"
		,	distance
	);
}

Cry::Entity::EventFlags CInteraction::GetEventMask() const
{
	return Cry::Entity::EEvent::Update;
}

void CInteraction::ProcessEvent(const SEntityEvent& event)
{
	if (gEnv->IsEditing())
		return;

	const auto delta_time = event.fParam[0];
	if (time_interval_ -= delta_time; time_interval_ <= 0.0f) {
		time_interval_ = component_update_interval_;

		const auto& camera = gEnv->pSystem->GetViewCamera();
		const auto camera_position = camera.GetPosition();
		const auto camera_direction = camera.GetViewdir().GetNormalized();

		std::array skip_entities{ m_pEntity->GetPhysicalEntity() };

		gEnv->pPhysicalWorld->RayWorldIntersection(
				camera_position
			,	camera_direction * distance_
			,	ent_static | ent_rigid | ent_sleeping_rigid
			,	rwi_stop_at_pierceable
			,	std::addressof(hit_result_)
			,	1
			,	skip_entities.data()
			,	skip_entities.size()
		);
	}
}