#include "particleSystem.h"

ParticleSystem::ParticleSystem() : _particles(0)
{
	// Particula uniforme
	/*_particle_generators.push_back(new UniformParticleGenerator("uniform", { 10.0, 20.0, 10.0 }, { 5.0, -10.0, 5.0 }, 0.5,
		new Particle({ 5.0, 5.0, 5.0 }, { 10.0, 10.0, 0.0 }), { 10.0, 10.0, 0.0 }, { 5.0, 5.0, 5.0 }));*/

	// Particula gaussiana
	/*_particle_generators.push_back(new GaussianParticleGenerator("gaussian", { 10.0, 20.0, 10.0 }, { 5.0, -10.0, 5.0 }, 0.5,
		new Particle({ 5.0, 5.0, 5.0 }, { 10.0, 10.0, 0.0 }), { 10.0, 10.0, 10.0 }, { 5.0, 5.0, 5.0 }, 5.0));*/
}

ParticleSystem::~ParticleSystem()
{
	for (auto it = _particles.begin(); it != _particles.end(); ++it) {

		delete* it;
		it = _particles.erase(it);

	}
}

void ParticleSystem::update(double t)
{
	/*for (auto p = _particle_generators.begin(); p != _particle_generators.end(); ++p)
	{
		if (_particles.size() < 10)
		{
			auto l = (*p)->generateParticles();

			for (auto q = l.begin(); q != l.end(); ++q)
				_particles.push_back((*q));
		}
	}*/

	// integrate de cada particula
	auto p = _particles.begin();
	while (p != _particles.end())
	{
		(*p)->integrate(t);

		// Elimina la particula si ha muerto
		if (!(*p)->getAlive())
		{
			delete (*p);
			p = _particles.erase(p);
		}
		else ++p;
	}
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	for (auto g : _particle_generators)
	{
		//if (g->getName() == name)
			return g;
	}
}

void ParticleSystem::createFogSystem()
{
	/*Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0, 30.0, 0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double time = 5.0;
	double mass = 0.5;
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc);
	p->setColor(Vector4{ 0.0f, 0.0f, 1.f, 1 });

	UniformParticleGenerator *uniformGenerator = new UniformParticleGenerator("Uniforme", { 5, 0, 5 }, { 10, 0, 10 }, 0.8, 40, p);

	_particle_generators.push_back(uniformGenerator);*/
}
