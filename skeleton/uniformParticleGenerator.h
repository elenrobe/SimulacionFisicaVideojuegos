#pragma once
#include "ParticleGenerator.h"
#include <random>


class UniformParticleGenerator : public ParticleGenerator
{
public:
	UniformParticleGenerator(Vector3 pos, Vector3 vel, double genProb, Particle* model, Vector3 posWidth, Vector3 velWidth);

	vector<Particle*> generateParticles() override;

protected:
	Vector3 _pos_width, _vel_width;
	std::mt19937 random_generator;

};