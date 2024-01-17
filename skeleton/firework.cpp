#include "Firework.h"

Firework* Firework::clone() const
{
	Firework* f = new Firework(pos.p, vel, acc, damping,tiempoVida, color, scale, mass, type);
	return f;
}

vector<Particle*> Firework::explode()
{
	if (type == 1) {

		vector<Particle*> generations;
		//si es de cada tipo que explote o no
		Particle* p = new Particle(pos.p, vel, acc, damping, 100, color, scale, SPHERE, mass);

		p->getPos().q = GetCamera()->getTransform().q;
		CircleParticleGenerator* g = new CircleParticleGenerator({ 5, 5, 5 }, 1, 10, p, 4);
		generations.push_back(p);

		for (Particle* r : g->generateParticles())
		{
			generations.push_back(r);
		}

		return generations;
	}
	else {

		vector<Particle*> generations;
		//si es de cada tipo que explote o no
		Firework* p = new Firework(pos.p, vel, acc, damping, 100, color, scale, mass, type-1);

		CircleParticleGenerator* g = new CircleParticleGenerator({ 5, 5, 5 }, 1, 10, p, 6);
		generations.push_back(p);

		for (Particle* r : g->generateParticles())
		{
			generations.push_back(r);
		}
		return generations;
	}

}

ParticleGenerator* Firework::addGenerator(ParticleGenerator* p)
{
	return gen;
}
