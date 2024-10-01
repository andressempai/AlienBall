#pragma once

#include "../../Utils/KeysAndToolsValues.h"

#include <CryEntitySystem/IEntityComponent.h>

#include <bitset>

class CToolBox final : public IEntityComponent {
public:
	static void ReflectType(Schematyc::CTypeDesc<CToolBox>& desc);

	void store(EKeysAndToolsValues value);
	bool use(EKeysAndToolsValues value);

private:
	std::bitset<static_cast<size_t>(EKeysAndToolsValues::max_keys_and_tools)> mask_{};
};