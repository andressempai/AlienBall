#pragma once

#include "../Interactable.h"

class CStatuette final : public IInteractable {
public:
	static void ReflectType(Schematyc::CTypeDesc<CStatuette>& desc);

private:
	void interact(IEntity& entity) override;
};