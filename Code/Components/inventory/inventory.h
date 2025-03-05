#pragma once

#include <CryEntitySystem/IEntityComponent.h>

#include <variant>

struct weapon {
	int damage_{};
	int ammo_{};
	int maxAmmo_{};
};

struct armor {
	int hardness_{};
};

class inventory : public IEntityComponent {
public:
	friend void ReflectType(Schematyc::CTypeDesc<inventory>& desc);

	void add_item(const std::variant<weapon, armor>& item_to_add);
	void use_all_items();

private:
	std::vector<std::variant<weapon, armor>> items_;
};