#include "inventory.h"

#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CryCore/StaticInstanceList.h>

void register_inventory(Schematyc::IEnvRegistrar& registrar)
{
	registrar.Scope(IEntity::GetEntityScopeGUID()).Register(SCHEMATYC_MAKE_ENV_COMPONENT(inventory));
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&register_inventory);

void ReflectType(Schematyc::CTypeDesc<inventory>& desc) {
	desc.SetGUID("{286EF6AA-1C73-4328-8F10-72C944252D54}"_cry_guid);
	desc.SetName(Schematyc::CTypeName{ "inventorycomponent" });
	desc.SetEditorCategory("GameComponents");
	desc.SetLabel("Inventory Component");
	desc.SetComponentFlags(IEntityComponent::EFlags::Singleton);
}

void inventory::add_item(const std::variant<weapon, armor>& item_to_add)
{
	items_.push_back(item_to_add);
}

void inventory::use_all_items()
{
	struct visit_item {
		void operator()(const weapon& item)
		{
			CryLogAlways("Weapon: damage %d, ammo %d, max ammo %d", item.damage_, item.ammo_, item.maxAmmo_);
		}

		void operator()(const armor& item)
		{
			CryLogAlways("Armor: hardness %d", item.hardness_);
		}
	};

	for (auto& item : items_)
		std::visit(visit_item{}, item);
}