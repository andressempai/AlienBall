#include "Statuette.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>
#include <CryPhysics/physinterface.h>

void register_statuette(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CStatuette));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_statuette);

void CStatuette::ReflectType(Schematyc::CTypeDesc<CStatuette>& desc)
{
	desc.AddBase<IInteractable>();
	desc.SetGUID("{CB4D537E-FD08-4E56-9C6E-E823A166A8E9}"_cry_guid);
	desc.SetEditorCategory("Interactables");
	desc.SetName(Schematyc::CTypeName("statuette"));
	desc.SetLabel("Statuette");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
}

void CStatuette::interact(IEntity& entity)
{
	auto physicalize_params = SEntityPhysicalizeParams{};
	physicalize_params.type = PE_NONE;
	m_pEntity->Physicalize(physicalize_params);

	entity.AttachChild(m_pEntity, SChildAttachParams{ IEntity::EAttachmentFlags::ATTACHMENT_KEEP_TRANSFORMATION });
}