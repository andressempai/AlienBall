#include "KeyOrTool.h"
#include "../ToolBox/ToolBox.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>
#include <CryEntitySystem/IEntitySystem.h>

void register_key_or_tool(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CKeyOrTool));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_key_or_tool);

void CKeyOrTool::ReflectType(Schematyc::CTypeDesc<CKeyOrTool>& desc)
{
	desc.AddBase<IInteractable>();
	desc.SetGUID("{E94997F1-0E21-4087-AF50-0311E1681C51}"_cry_guid);
	desc.SetEditorCategory("Interactables");
	desc.SetName(Schematyc::CTypeName("keyortool"));
	desc.SetLabel("Key Or Tool");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
	desc.AddMember(
			&CKeyOrTool::value_
		,	'ktva'
		,	"value"
		,	"Value"
		,	"Value"
		,	EKeysAndToolsValues::scorpion_key
	);
}

void CKeyOrTool::interact(IEntity& entity)
{
	if (auto* const keys_and_tools = entity.GetComponent<CToolBox>()) {
		keys_and_tools->store(value_);
		gEnv->pEntitySystem->RemoveEntity(GetEntityId());
	}
}