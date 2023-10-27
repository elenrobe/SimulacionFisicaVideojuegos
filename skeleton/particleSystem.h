#pragma once
#include <iostream>
#include <vector>

class Particle;
class ParticleGenerator;

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);
	//ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
	//void onParticleDeath(Particle* p);
	void createFogSystem();
	void createMangueraSystem();

protected:
	std::vector<Particle*> _particles;
	std::vector<ParticleGenerator*> _particle_generators;
};