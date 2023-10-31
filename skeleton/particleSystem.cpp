#include "ParticleSystem.h"

#include "GaussianParticleGenerator.h"

ParticleSystem::ParticleSystem() 
{
	createFogSystem();
	createMangueraSystem();
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
	for (auto g : _particle_generators)
	{
		for (Particle* p : g->generateParticles())
		{
			_particles.push_back(p);
		}
	}

	// integrate de cada particula

	for (int i = 0; i < _particles.size(); i++) {
		_particles[i]->integrate(t);
		if (!_particles[i]->getAlive()) {
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		}
	}
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name)
{
	for (auto g : _particle_generators)
	{
		if (g->getName() == name)
			return g;
	}
}

void ParticleSystem::generateFireworkSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc, { 255, 255, 255, 1 });

	

	GaussianParticleGenerator* gaussianGenerator = new GaussianParticleGenerator(
		{ 10.0, 20.0, 10.0 }, { 5.0, -10.0, 5.0 }, 0.5, 5, p,
		{ 10,10,10 }, { 10,10,10 });

}
//
//void ParticleSystem::onParticleDeath(Particle* p)
//{
//	if (p->getType() == FIREWORK)
//	{/*
//		Firework* f = dynamic_cast<Firework*>(p);
//		if (f != nullptr) {
//			f->explode();
//			for (auto p : f->explode())
//				_particles.push_back(p);
//		}*/
//	}
//}

void ParticleSystem::createFogSystem()
{

	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc, { 255, 255, 255, 1 });

	p->setAcc(Vector3(1, 0.0f, 0));
	p->setDamping(0.99f);

	UniformParticleGenerator* uniformGenerator = new UniformParticleGenerator({ 5, 0, 5 }, { 0, 0, 0 }, 1, p, { 10,10,10 }, { 10,10,10 });

	_particle_generators.push_back(uniformGenerator);
}

void ParticleSystem::createMangueraSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc, { 255, 255, 255, 1 });

	p->setAcc(Vector3(1, 0.0f, 0));
	p->setDamping(0.99f);

	GaussianParticleGenerator* gaussianGenerator = new GaussianParticleGenerator( { 5, 0, 5 }, { 0, 0, 0 }, 0.4, 5, p, { 60,10,60 }, { 10,10,10 });

	_particle_generators.push_back(gaussianGenerator);
}
