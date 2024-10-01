#pragma once

#include <CrySchematyc/Reflection/TypeDesc.h>

enum struct EKeysAndToolsValues : uint8 {
		scorpion_key
	,	crow_key
	,	hammer
	,	screwdriver
	,	max_keys_and_tools
};

static void ReflectType(Schematyc::CTypeDesc<EKeysAndToolsValues>& desc)
{
	desc.SetGUID("{2A952052-1571-44AD-8221-22F114F86B22}"_cry_guid);
	desc.SetDescription("Keys and Tools Values");
	desc.AddConstant(EKeysAndToolsValues::scorpion_key, "scke", "Scorpion Key");
	desc.AddConstant(EKeysAndToolsValues::crow_key, "crke", "Crow Key");
	desc.AddConstant(EKeysAndToolsValues::hammer, "hamm", "Hammer");
	desc.AddConstant(EKeysAndToolsValues::screwdriver, "scre", "Screwdriver");
}