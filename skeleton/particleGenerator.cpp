#include "ParticleGenerator.h"
//
//ParticleGenerator::ParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles, Particle* model)
//{
//	_name = name;
//	_mean_pos = pos;
//	_mean_vel = vel;
//	_generation_probability = genProb;
//	_num_particles = numParticles;
//	_model = model;
//}

ParticleGenerator::ParticleGenerator()
{
}

ParticleGenerator::~ParticleGenerator()
{
	delete _model; 
}

void ParticleGenerator::setParticle(Particle* model)
{ 
	_model = model;
}

std::vector<Particle*> ParticleGenerator::generateParticles()
{
	return std::vector<Particle*>();
}
