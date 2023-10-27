#pragma once
#include "particleGenerator.h"
#include <time.h>
#include <random>

class GaussianParticleGenerator : public ParticleGenerator
{

public:
	GaussianParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles, Particle* model, Vector3 std_dev_pos, Vector3 std_dev_vel);
	virtual vector<Particle*> generateParticles();
private:
	Vector3 std_dev_pos, std_dev_vel;
	double std_dev_t;
	std::mt19937 random_generator;


};