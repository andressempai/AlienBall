#include "Door.h"
#include "../ToolBox/ToolBox.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>
#include <CryEntitySystem/IEntitySystem.h>

void register_door(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CDoor));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_door);

void CDoor::ReflectType(Schematyc::CTypeDesc<CDoor>& desc)
{
	desc.AddBase<IInteractable>();
	desc.SetGUID("{6396FF9F-0F64-4A5D-B334-692EE4449D8A}"_cry_guid);
	desc.SetEditorCategory("Interactables");
	desc.SetName(Schematyc::CTypeName("door"));
	desc.SetLabel("Door");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
	desc.AddMember(
			&CDoor::key_needed_
		,	'kyne'
		,	"keyneeded"
		,	"Key Needed"
		,	"Needed Key to Open the Door"
		,	EKeysAndToolsValues::scorpion_key
	);
}

void CDoor::interact(IEntity& entity)
{
	if (auto* const keys_and_tools = entity.GetComponent<CToolBox>()) {
		if (keys_and_tools->use(key_needed_))
			CryWarning(VALIDATOR_MODULE_GAME, VALIDATOR_WARNING, "The Door is Open");
	}
}