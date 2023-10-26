#include "particleSystem.h"
#include "uniformParticleGenerator.h"

ParticleSystem::ParticleSystem()
{
	// Particula uniforme
	/*_particle_generators.push_back(new UniformParticleGenerator("uniform", { 10.0, 20.0, 10.0 }, { 5.0, -10.0, 5.0 }, 0.5,
		new Particle({ 5.0, 5.0, 5.0 }, { 10.0, 10.0, 0.0 }), { 10.0, 10.0, 0.0 }, { 5.0, 5.0, 5.0 }));*/

	// Particula gaussiana
	/*_particle_generators.push_back(new GaussianParticleGenerator("gaussian", { 10.0, 20.0, 10.0 }, { 5.0, -10.0, 5.0 }, 0.5,
		new Particle({ 5.0, 5.0, 5.0 }, { 10.0, 10.0, 0.0 }), { 10.0, 10.0, 10.0 }, { 5.0, 5.0, 5.0 }, 5.0));*/

	createFogSystem();
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

	//Particle* up = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 1, 1, { 0,0,1 }, 1000, false);
	//UniformParticleGenerator* uG = new UniformParticleGenerator({ -20,0,0 }, { 0,0,0 }, { 10,10,10 }, { 10,10,10 }, 1, 10);
	//uG->setParticle(up);
	//_particle_generators.push_back(uG);

	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 1,1,1 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double time = 5.0;
	double mass = 0.5;
	double damp = 0.95;
	Particle* p = new Particle(pos, vel, acc);
	p->setMass(2.0f);
	p->setVel(vel * 35);
	p->setAcc(Vector3(0, -1.0f, 0));
	p->setDamping(0.99f);
	p->setColor(Vector4{ 0.0f, 1.0f, 1.f, 0.5 });

	UniformParticleGenerator *uniformGenerator = new UniformParticleGenerator("Uniforme", { 5, 0, 5 }, { 10, 0, 10 }, 1, 40, p, { 10,10,10 }, { 10,10,10 });

	_particle_generators.push_back(uniformGenerator);
}
