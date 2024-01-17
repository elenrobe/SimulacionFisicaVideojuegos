#pragma once

#include "UniformParticleGenerator.h"
#include "Particle.h"
#include "BuoyancyForceGenerator.h"
#include "ParticleForceRegistry.h"
#include "GravityForceGenerator.h"
#include "CircleForceGenerator.h"
#include "SpringForceGenerator.h"
#include "AnchoredSpringForceGenerator.h"


class Tiovivo
{
	UniformParticleGenerator* generator_;
	Particle* base_;
	Particle* capsula_;
	std::vector<Particle*> particles;
	std::vector<ForceGenerator*> forceGenerators;

	GravityForceGenerator* gravityForceGen = nullptr;
	
	BuoyancyForceGenerator* buoyancyForceGen = nullptr;

	CircleForceGenerator* c = nullptr;
	SpringForceGenerator* s = nullptr;

public:
	Tiovivo(Vector3 pos, std::unique_ptr<ParticleForceRegistry>& pFR);
	~Tiovivo();
	std::vector<Particle*> getParticles() {
		return particles;
	}
	std::vector<ForceGenerator*> getFGens() {
		return forceGenerators;
	}

	/*physx::PxShape* B = CreateShape(physx::PxBoxGeometry(2, 2, 2));
	RBParticle* r = new RBParticle({ 7,60,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 5, gPhysics, gScene, B, false, 900);
	_particles.push_back(r);


	buoyancyForceGen = new BuoyancyForceGenerator(10.0, 1, 1000, Vector3(7, 50, 7));
	rb_pFR->addRegistry(buoyancyForceGen, r->getDynamicRigid());*/

};

