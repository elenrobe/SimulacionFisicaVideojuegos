#pragma once
#include "ParticleGenerator.h"
#include <iostream>
#include <random>
class CircleParticleGenerator : public ParticleGenerator
{
	std::uniform_real_distribution<double> gen_prob_dist;
	std::default_random_engine gen_;
	double radius_;
	double cvel;

public:
	CircleParticleGenerator(Vector3 meanVel, double gen_prob, double radius, Particle* model, double numPart = 10);
	CircleParticleGenerator() {};

	virtual vector<Particle*> generateParticles();
};

