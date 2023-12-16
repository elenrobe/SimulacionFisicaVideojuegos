#pragma once
#include <iostream>

#include "RBParticle.h"
#include "GravityForceGenerator.h"
#include "WindForceGenerator.h"
#include "WhirlwindForceGenerator.h"
#include "ExplosionForceGenerator.h"
#include "BuoyancyForceGenerator.h"
#include "RBParticleForceRegistry.h"

class RBParticleSystem
{

	std::vector<RBParticle*> _particles;
	std::unique_ptr<RBParticleForceRegistry> rb_pFR;
	GravityForceGenerator* gravityForceGen = nullptr;
	WindForceGenerator* windForceGen = nullptr;
	WhirlwindForceGenerator* whirlwindForceGen = nullptr;
	ExplosionForceGenerator* explosionForceGen = nullptr;
	BuoyancyForceGenerator* buoyancyForceGen = nullptr;


	
	void addGravity();
	void changeGravity() { gravityOn = !gravityOn; };
	void addWind();
	void changeWind() { windOn = !windOn; };
	void addWhirlwind();
	void changeWhirlwind() { whirlwindOn = !whirlwindOn; };
	void addExplosion();
	void changeExplosion() { explosionOn = !explosionOn; };

	bool gravityOn = false, windOn = false, whirlwindOn = false, explosionOn = false;

public:
	RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~RBParticleSystem();
	void update(double t);

	void generateParticles();


};

