#pragma once

#include "../Interactable.h"
#include "../../Utils/KeysAndToolsValues.h"

class CDoor final : public IInteractable {
public:
	static void ReflectType(Schematyc::CTypeDesc<CDoor>& desc);

private:
	void interact(IEntity& entity) override;

	EKeysAndToolsValues key_needed_{};
};