#pragma once

#include "../Interactable.h"

class CPedestal final : public IInteractable {
public:
	static void ReflectType(Schematyc::CTypeDesc<CPedestal>& desc);

private:
	void interact(IEntity& entity) override;

	bool has_statuette_{};
};