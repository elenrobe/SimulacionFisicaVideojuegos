#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() 
{
	setUpFireworks();
	//createFogSystem();
	//createFireSystem();
	//createMangueraSystem();
	//generateFireworkSystem();
	shootFirework(0);
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



			if (_particles[i]->getType() == FIREWORK)
			{
				//Firework* f = dynamic_cast<Firework*>(_particles[i]);
				if (_particles[i] != nullptr) {
					cout << "EXPLOTA";
					vector<Particle*> v = _particles[i]->explode();
					
					for (auto p : v)
						_particles.push_back(p);

				}
			}

			//delete _particles[i];
			//_particles.erase(_particles.begin() + i);
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
	float lifeTime = 2000;
	Vector4 color = { 255,0,0,1 };
	float scale = 1;


	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale);


	shared_ptr<ParticleGenerator> pG1(new GaussianParticleGenerator({ 5, 0, 5 }, { 0, 0, 0 }, 0.4, 5, p, { 60,10,60 }, { 10,10,10 }));
	Firework* f = new Firework(pos, vel, acc, damp, lifeTime, color, scale);
	_particles.push_back(f);

}

void ParticleSystem::shootFirework(int type)
{
	

	Firework* f = _fireworks_pool[0]->clone();

	_particles.push_back(f);

}
void ParticleSystem::setUpFireworks()
{
	Vector3 pos = { 0.0, 50.0, 0.0 };
	Vector3 vel = { 0,60,0 };
	Vector3 acc = { 0.0f, -2.8f, 0.0f };
	double damp = 0.95;
	float lifeTime = 100;
	Vector4 color = { 255,0,0,1 };
	float scale = 1;

	//hacemos tres tipos de particulas para los fireworks
	Firework* f = new Firework(pos, vel, acc, damp, lifeTime, color, scale);
	_fireworks_pool.push_back(new Firework(pos, vel, acc, damp, lifeTime, color, scale));


}
void ParticleSystem::onParticleDeath(Particle* p)
{
	if (p->getType() == FIREWORK)
	{
		Firework* f = dynamic_cast<Firework*>(p);
		if (f != nullptr) {
			f->explode();
			cout << "EXPLOTA";
			for (auto p : f->explode())
				_particles.push_back(p);
		}
	}
}

void ParticleSystem::createFogSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	float lifeTime = 40;
	Vector4 color = { 0,255,255,1 };
	float scale = 1;

	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale);


	UniformParticleGenerator* uniformGenerator = new UniformParticleGenerator({ 5, 0, 5 }, { 0, 30, 0 }, 1, p, { 1,1,1 }, { 6,20,6 });

	_particle_generators.push_back(uniformGenerator);
}

void ParticleSystem::createMangueraSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.99;
	float lifeTime = 150;
	Vector4 color = { 255,255,255,1 };
	float scale = 2;

	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale);

	GaussianParticleGenerator* gaussianGenerator = new GaussianParticleGenerator( { 5, 0, 5 }, { 0, 0, 0 }, 0.4, 5, p, { 60,10,60 }, { 5,5,5 });

	_particle_generators.push_back(gaussianGenerator);
}

void ParticleSystem::createFireSystem()
{
	Vector3 pos = { 90.0, 68.0, 0.0 };
	Vector3 vel = { 0,2,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	float lifeTime = 100;
	Vector4 color = { 255,0,0,1 };
	float scale = 1;

	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale);


	CircleParticleGenerator* c = new CircleParticleGenerator({ 5, 5, 5 }, 1, 10, p);

	_particle_generators.push_back(c);
}

Vector4 ParticleSystem::rndColor()
{
	std::random_device rnd;
	std::default_random_engine gen_(rnd());
	std::uniform_real_distribution<> distr(0, 1);

	Vector4 color;

	color.x = distr(gen_);
	color.y = distr(gen_);
	color.z = distr(gen_);
	color.w = 1.0;
	return color;
}
