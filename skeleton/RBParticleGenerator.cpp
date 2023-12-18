#include "RBParticleGenerator.h"

RBParticleGenerator::RBParticleGenerator()
{
}

RBParticleGenerator::~RBParticleGenerator()
{
	//delete _model;
}

void RBParticleGenerator::setParticle(RBParticle* model)
{
	_model = model;
}

std::vector<RBParticle*> RBParticleGenerator::generateParticles()
{
	return std::vector<RBParticle*>();
}
