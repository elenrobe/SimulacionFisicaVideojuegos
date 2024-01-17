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

};

