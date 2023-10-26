#include "particleGenerator.h"

ParticleGenerator::ParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles)
{
	_name = name;
	_mean_pos = pos;
	_mean_vel = vel;
	_generation_probability = genProb;
	_num_particles = numParticles;
}

void ParticleGenerator::setParticle(Particle* model)
{
	_model = model;
}
