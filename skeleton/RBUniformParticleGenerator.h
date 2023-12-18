#pragma once
#include "RBParticleGenerator.h"
#include <random>


class RBUniformParticleGenerator : public RBParticleGenerator
{
public:
	RBUniformParticleGenerator(Vector3 pos, Vector3 vel, double genProb, RBParticle* model, Vector3 posWidth, Vector3 velWidth);

	vector<RBParticle*> generateParticles() override;

protected:
	Vector3 _pos_width, _vel_width;
	std::mt19937 random_generator;

};