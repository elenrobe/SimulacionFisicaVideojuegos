#include "particleSystem.h"
//#include "uniformParticleGenerator.h"
#include "gaussianParticleGenerator.h"

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
	for (ParticleGenerator* g : _particle_generators)
	{
		vector<Particle*> aux = g->generateParticles();
		for (Particle* p : aux)
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
		//if (g->getName() == name)
			return g;
	}
}

void ParticleSystem::createFogSystem()
{

	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc, { 255, 255, 255, 1 });

	p->setAcc(Vector3(1, 0.0f, 0));
	p->setDamping(0.99f);

	/*UniformParticleGenerator *uniformGenerator = new UniformParticleGenerator("Uniforme", { 5, 0, 5 }, { 0, 0, 0 }, 1, 5, p, { 10,10,10 }, { 10,10,10 });

	_particle_generators.push_back(uniformGenerator);*/
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

	GaussianParticleGenerator* gaussianGenerator = new GaussianParticleGenerator("Gaussian", { 5, 0, 5 }, { 0, 0, 0 }, 0.4, 5, p, { 10,10,10 }, { 10,10,10 });

	_particle_generators.push_back(gaussianGenerator);
}
