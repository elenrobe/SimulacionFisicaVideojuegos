#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ParticleGenerator.h"
#include "UniformParticleGenerator.h"
#include "GaussianParticleGenerator.h"
#include "CircleParticleGenerator.h"
#include "Firework.h"
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
	void createFogSystem();
	void createMangueraSystem();
	void createFireSystem();
	Vector4 rndColor();


protected:
	std::vector<Particle*> _particles;
	std::vector<ParticleGenerator*> _particle_generators;
	std::vector<Firework*> _fireworks_pool; //con los datos de los fireworks
};