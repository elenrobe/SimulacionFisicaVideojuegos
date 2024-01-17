#pragma once
#include <iostream>

#include "RBParticle.h"
#include "GravityForceGenerator.h"
#include "WindForceGenerator.h"
#include "WhirlwindForceGenerator.h"
#include "ExplosionForceGenerator.h"
#include "BuoyancyForceGenerator.h"
#include "RBParticleForceRegistry.h"
#include "RBParticleGenerator.h"
#include "RBUniformParticleGenerator.h"
#include "Noria.h"
#include "RBProjectile.h"
#include "Snowman.h"

class RBParticleSystem
{

	std::vector<RBParticle*> _particles;
	std::vector<RBParticleGenerator*> _particle_generators;
	std::vector<Snowman*> _snowmen;

	std::unique_ptr<RBParticleForceRegistry> rb_pFR;
	GravityForceGenerator* gravityForceGen = nullptr;
	WindForceGenerator* windForceGen = nullptr;
	WhirlwindForceGenerator* whirlwindForceGen = nullptr;
	ExplosionForceGenerator* explosionForceGen = nullptr;
	BuoyancyForceGenerator* buoyancyForceGen = nullptr;


	physx::PxPhysics* gPhysics;
	physx::PxScene* gScene;

	bool windOn = false, whirlwindOn = false, explosionOn = false;

public:
	RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene);
	~RBParticleSystem();
	void update(double t);

	void generateFinalScene(); //proyecto final
	void generateNoria(); //proyecto final
	void generateSnowman(); //proyecto final

	void shootBullet(); //proyecto final
	void checkCollisions(physx::PxActor* snowman, physx::PxActor* actor2);


	void generateParticles();
	void deleteAll();

	void createManguerSystem();


	
	void addWind();
	void changeWind() { windOn = !windOn; };
	void addWhirlwind();
	void changeWhirlwind() { whirlwindOn = !whirlwindOn; };
	void addExplosion();
	void changeExplosion() { explosionOn = !explosionOn; };



};

