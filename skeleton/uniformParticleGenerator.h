#pragma once
#include "particleGenerator.h"
#include <time.h>
#include <random>

class UniformParticleGenerator : public ParticleGenerator
{
public:
	UniformParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles, Particle* model, Vector3 posWidth, Vector3 velWidth );
	virtual vector<Particle*> generateParticles();
private:
	Vector3 _pos_width, _vel_width;
	std::mt19937 random_generator;

};