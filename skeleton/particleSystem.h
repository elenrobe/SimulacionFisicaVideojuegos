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
	void createNieblaSystem();
	void createFireSystem();
	Vector4 rndColor();
	void addGravity();
	void changeGravity() { gravityOn = !gravityOn; };

protected:
	std::vector<Particle*> _particles;
	std::vector<ParticleGenerator*> _particle_generators;
	std::vector<Firework*> _fireworks_pool; //con los datos de los fireworks

	unique_ptr<ParticleForceRegistry> pFR;
	GravityForceGenerator* gravityForceGen = nullptr;

	
	bool gravityOn = false;
};