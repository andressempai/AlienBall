#pragma once

#include "../Interactable.h"

class CLightSwitch final : public IInteractable {
public:
	static void ReflectType(Schematyc::CTypeDesc<CLightSwitch>& desc);

private:
	void interact(IEntity& entity) override;
};