#include "LightSwitch.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>

void register_light_switch(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CLightSwitch));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_light_switch);

void CLightSwitch::ReflectType(Schematyc::CTypeDesc<CLightSwitch>& desc)
{
	desc.AddBase<IInteractable>();
	desc.SetGUID("{36A75001-F83F-4A44-9F43-76C29FC87574}"_cry_guid);
	desc.SetEditorCategory("Interactables");
	desc.SetName(Schematyc::CTypeName("lightswitch"));
	desc.SetLabel("Light Switch");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
}

void CLightSwitch::interact(IEntity& entity)
{
	CryLog("Hello from Light Switch");
}