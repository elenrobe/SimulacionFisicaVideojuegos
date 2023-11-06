#include "Firework.h"

Firework* Firework::clone() const
{
	Firework* f = new Firework(pos.p, vel, acc, damping,tiempoVida, color, scale);
	return f;
}

vector<Particle*> Firework::explode()
{
	vector<Particle*> generations;
	Particle* p = clone();

	CircleParticleGenerator* g = new CircleParticleGenerator({ 5, 5, 5 }, 1, 10, p, 6);

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
