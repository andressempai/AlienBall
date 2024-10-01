#pragma once

#include "../Interactable.h"
#include "../../Utils/KeysAndToolsValues.h"

class CKeyOrTool final : public IInteractable {
public:
	static void ReflectType(Schematyc::CTypeDesc<CKeyOrTool>& desc);

private:
	void interact(IEntity& entity) override;

	EKeysAndToolsValues value_{};
};