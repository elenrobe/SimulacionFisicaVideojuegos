#pragma once
#include "RBParticle.h"

class RBParticleSystem
{

	std::vector<RBParticle*> _particles;

public:
	RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~RBParticleSystem();
	void update(double t);

};

