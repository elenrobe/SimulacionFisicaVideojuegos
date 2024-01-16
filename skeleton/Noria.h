#pragma once
#include "RBParticle.h"
#include <iostream>
#include <random>
class Noria
{
	RBParticle* centro_;
	RBParticle* base_;
	std::vector<RBParticle*> cabinas;
public:
	Noria(physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~Noria();

};

