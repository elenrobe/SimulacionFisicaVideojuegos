#include "firework.h"

Firework* Firework::clone() const
{
	Firework* f;
	return f;
}

list<Particle*> Firework::explode()
{
	list<Particle*> generations;

	for (auto g : _gens)
	{
		auto particles = g->generateParticles();
		for (auto q : particles)
			generations.push_back(q);
	}

	return generations;
}