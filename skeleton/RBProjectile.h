#pragma once
#include "RBParticle.h"
class RBProjectile : public RBParticle
{
public:
	enum TYPE { PISTOL, ARTILLERY, FIREBALL, LASER, BASE };

	RBProjectile(TYPE type, physx::PxPhysics* gPhysics, physx::PxScene* gScene);



	~RBProjectile();

private:
};