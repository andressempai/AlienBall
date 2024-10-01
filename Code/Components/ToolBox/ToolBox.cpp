#include "ToolBox.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>

void register_kesy_and_tools(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CToolBox));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_kesy_and_tools);

void CToolBox::ReflectType(Schematyc::CTypeDesc<CToolBox>& desc)
{
	desc.SetGUID("{CCD214A9-6732-4D7E-8207-5CB364CBAC98}"_cry_guid);
	desc.SetEditorCategory("Game Components");
	desc.SetName(Schematyc::CTypeName("toolbox"));
	desc.SetLabel("Tool Box");
	desc.SetDescription("Allow Entity to store Keys and Tools.");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
}

void CToolBox::store(EKeysAndToolsValues value)
{
	mask_.set(static_cast<size_t>(value));
}

bool CToolBox::use(EKeysAndToolsValues value)
{
	if (mask_.test(static_cast<size_t>(value))) {
		mask_.set(static_cast<size_t>(value), false);

		return true;
	}

	return false;
}