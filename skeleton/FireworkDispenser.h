#pragma once

#include "RBParticle.h"
#include <iostream>
//literalmente solo un cuadrado del que vayan a salir los fuegos artificiales
class FireworkDispenser
{
public:
	FireworkDispenser(Vector3 pos, physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~FireworkDispenser();
};

