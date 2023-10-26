#pragma once
#include <iostream>
#include"particle.h"

using namespace std;
class ParticleGenerator;

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
	Vector3 _gravity = { 0,-10,0 };

};