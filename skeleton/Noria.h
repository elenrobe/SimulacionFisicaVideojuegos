#pragma once
#include "RBParticle.h"
#include <iostream>
#include <random>
class Noria
{
	RBParticle* centro_;
	RBParticle* base_;
	std::vector<RBParticle*> particles;
public:
	Noria(Vector3 pos,physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~Noria();
	std::vector<RBParticle*> getParticles() {
		return particles;
	}
};

