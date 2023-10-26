#pragma once
#include <iostream>
#include"particle.h"
#include"particleGenerator.h"

using namespace std;

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
	void onParticleDeath();
	void createFogSystem();

protected:
	vector<Particle*>_particles;
	vector<ParticleGenerator*>_particle_generators;

};