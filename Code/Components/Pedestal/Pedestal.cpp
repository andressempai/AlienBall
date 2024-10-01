#include "Pedestal.h"
#include "../Statuette/Statuette.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>

void register_pedestal(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(CPedestal));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_pedestal);

void CPedestal::ReflectType(Schematyc::CTypeDesc<CPedestal>& desc)
{
	desc.AddBase<IInteractable>();
	desc.SetGUID("{8BFBFBAB-0BF9-4135-80CB-5B1426C6A4C6}"_cry_guid);
	desc.SetEditorCategory("Interactables");
	desc.SetName(Schematyc::CTypeName("pedestal"));
	desc.SetLabel("Pedestal");
	desc.SetComponentFlags(EEntityComponentFlags::Singleton);
}

void CPedestal::interact(IEntity& entity)
{
	if (has_statuette_)
		return;

	for (auto iter = 0; iter < entity.GetChildCount(); ++iter) {
		if (auto* const child = entity.GetChild(iter)) {
			if (child->GetComponent<CStatuette>()) {
				m_pEntity->AttachChild(child);
				has_statuette_ = true;

				const auto offset = Matrix34::Create(child->GetWorldTM().GetScale(), IDENTITY, Vec3{ 0.0f, 0.0f, 0.35f });
				child->SetWorldTM(m_pEntity->GetWorldTM() * offset);
				return;
			}
		}
	}

#ifndef RELEASE
		CryWarning(VALIDATOR_MODULE_GAME, VALIDATOR_WARNING, "You Need place an Statuette, find it.");
#endif // RELEASE
}