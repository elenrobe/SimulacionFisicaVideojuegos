#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ParticleGenerator.h"
#include "UniformParticleGenerator.h"
#include "GaussianParticleGenerator.h"
#include "CircleParticleGenerator.h"
#include "Firework.h"


#include "ParticleForceRegistry.h"
#include "GravityForceGenerator.h"
#include "WindForceGenerator.h"
#include "WhirlwindForceGenerator.h"
#include "ExplosionForceGenerator.h"
#include "AnchoredSpringForceGenerator.h"
#include "SpringForceGenerator.h"
#include "ParticleBungee.h"
#include "BuoyancyForceGenerator.h"
#include "Tiovivo.h"


class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
	void shootFirework(int type);
	void setUpFireworks();
	void onParticleDeath(Particle* p);
	void createManguerSystem();
	void createNieveSystem();
	void createFireSystem();
	Vector4 rndColor();

	void addGravity();
	void changeGravity() { gravityOn = !gravityOn; };
	void addWind();
	void changeWind() { windOn = !windOn; };
	void addWhirlwind();
	void changeWhirlwind() { whirlwindOn = !whirlwindOn; };
	void addExplosion();
	void changeExplosion() { explosionOn = !explosionOn; };

	void addSomeParticles();

	void generateFinalScene();
	void createTiovivo();
	void createFuegos();

	void deleteAll();


	void muelleEstatico();
	void muelleDoble();
	void bungee();
	void createBuoyancyTest();
	void createSlinky();

protected:
	std::vector<Particle*> _particles;
	std::vector<ParticleGenerator*> _particle_generators;
	std::vector<Firework*> _fireworks_pool; //con los datos de los fireworks

	unique_ptr<ParticleForceRegistry> pFR;
	GravityForceGenerator* gravityForceGen = nullptr;
	WindForceGenerator* windForceGen = nullptr;
	WhirlwindForceGenerator* whirlwindForceGen = nullptr;
	ExplosionForceGenerator* explosionForceGen = nullptr;
	BuoyancyForceGenerator* buoyancyForceGen = nullptr;
	

	bool gravityOn = false, windOn = false, whirlwindOn = false, explosionOn = false;
};