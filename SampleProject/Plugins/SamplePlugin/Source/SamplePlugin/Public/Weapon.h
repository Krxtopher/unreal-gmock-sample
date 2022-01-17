#pragma once

class SAMPLEPLUGIN_API FWeapon
{

public:
	FWeapon();
	virtual ~FWeapon() {}

	virtual void Fire();
};