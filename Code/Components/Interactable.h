#pragma once

#include <CryEntitySystem/IEntityComponent.h>

struct IInteractable : IEntityComponent {
	static void ReflectType(Schematyc::CTypeDesc<IInteractable>& desc)
	{
		desc.SetGUID("{D16F037A-3286-4755-82A9-067BD16AFD24}"_cry_guid);
	}

	virtual void interact(IEntity& entity) = 0;
};