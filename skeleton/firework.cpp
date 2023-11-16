#include "Firework.h"

Firework* Firework::clone() const
{
	Firework* f = new Firework(pos.p, vel, acc, damping,tiempoVida, color, scale, mass);
	return f;
}

vector<Particle*> Firework::explode()
{
	vector<Particle*> generations;
	Particle* p = new Particle(pos.p, vel, acc, damping, 100, color, scale, SPHERE, mass);

	CircleParticleGenerator* g = new CircleParticleGenerator({ 5, 5, 5 }, 1, 10, p, 6);
	generations.push_back(p);

	for (Particle* r : g->generateParticles())
	{
		generations.push_back(r);
	}	

	return generations;
}

ParticleGenerator* Firework::addGenerator(ParticleGenerator* p)
{
	return gen;
}
