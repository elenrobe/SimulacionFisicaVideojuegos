#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() 
{
	pFR = make_unique<ParticleForceRegistry>();
	//setUpFireworks();
    //shootFirework(0);

	//createManguerSystem();
	addGravity();
	addWind();
	addWhirlwind();
	//createFireSystem();
	//createNieblaSystem();
	//generateFireworkSystem();
	//muelleEstatico();
	//muelleDoble();
	//createSlinky();
	createBuoyancyTest();
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
		auto v = g->generateParticles();

		//std::vector<ForceGenerator*> force = g->returnForce();

		for (Particle* p : v)
		{
			_particles.push_back(p);

			if (gravityOn) {

				pFR.get()->addRegistry(gravityForceGen, p);
			}
			if(windOn)
				pFR.get()->addRegistry(windForceGen, p);
			if (whirlwindOn)
				pFR.get()->addRegistry(whirlwindForceGen, p);
			
		}
		//gravityOn = false;
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
					//_particles[i]->kill();
					for (int i = 0; i < v.size();i++)
						_particles.push_back(v[i]);

				}
			}

			pFR.get()->deleteParticleRegistry(_particles[i]);
			//pFR.get()->deleteForce();
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		}
	}

	pFR.get()->updateForces(t);


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

	double mass = 1;
	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale, SPHERE, mass);


	shared_ptr<ParticleGenerator> pG1(new GaussianParticleGenerator({ 5, 0, 5 }, { 0, 0, 0 }, 0.4, 5, p, { 60,10,60 }, { 10,10,10 }));
	Firework* f = new Firework(pos, vel, acc, damp, lifeTime, color, scale, mass);
	_particles.push_back(f);

}

void ParticleSystem::shootFirework(int type)
{

	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,50,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	float lifeTime =100;
	Vector4 color = { 255,0,0,1 };
	float scale = 1;
	double mass = 1;

	Firework* f = new Firework(pos, vel, acc, damp, lifeTime, color, scale, mass);
	//Firework* f = _fireworks_pool[0]->clone();

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
	double mass = 1;

	//hacemos tres tipos de particulas para los fireworks
	Firework* f = new Firework(pos, vel, acc, damp, lifeTime, color, scale, mass);
	_fireworks_pool.push_back(f);
	_particles.push_back(f);


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

void ParticleSystem::createManguerSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.95;
	float lifeTime = 150;
	Vector4 color = { 0,255,255,1 };
	float scale = 1;
	double mass = 1;

	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale, SPHERE, mass);


	UniformParticleGenerator* uniformGenerator = new UniformParticleGenerator({ 5, 0, 5 }, { 0, 30, 0 }, 1, p, { 1,1,1 }, { 6,20,6 });

	_particle_generators.push_back(uniformGenerator);
}

void ParticleSystem::createNieblaSystem()
{
	Vector3 pos = { 0.0, 10.0, 0.0 };
	Vector3 vel = { 0,0,0 };
	Vector3 acc = { 0.0f, -9.8f, 0.0f };
	double damp = 0.99;
	float lifeTime = 150;
	Vector4 color = { 255,255,255,1 };
	float scale = 2;
	double mass = 1;
	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale, SPHERE, mass);

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
	double mass = 1;
	Particle* p = new Particle(pos, vel, acc, damp, lifeTime, color, scale, SPHERE, mass);


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

void ParticleSystem::addGravity()
{
	gravityForceGen = new GravityForceGenerator({ 0, -9.8, 0 });
	

	
}

void ParticleSystem::addWind()
{

	windForceGen = new WindForceGenerator(-1, 0, Vector3(10, 100, -10), { 7,50,7 }, 100);

}

void ParticleSystem::addWhirlwind()
{
	whirlwindForceGen = new WhirlwindForceGenerator(1, 0, 1.0, Vector3(9, 9, 9), { 7,50,7 }, 100);

}

void ParticleSystem::addExplosion()
{

	explosionForceGen = new ExplosionForceGenerator(2000, 1000, 400, Vector3(7, 50, 7));

	for (auto p : _particles)
		pFR.get()->addRegistry(explosionForceGen, p);

}

void ParticleSystem::addSomeParticles()
{

	_particles.push_back(new Particle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,0,255,1 }, 2, SPHERE, 1));
	_particles.push_back(new Particle({ 5,0,5 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,255,0,1 }, 9, SPHERE, 50));
	_particles.push_back(new Particle({ 5,25,15 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 255,0,0,1 }, 5, SPHERE, 25));
	_particles.push_back(new Particle({ 25,10,5 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,255,0,1 }, 2, SPHERE, 4));


}

void ParticleSystem::muelleEstatico()
{
	auto cube = CreateShape(physx::PxBoxGeometry(4, 2, 4));
	/*Particle* pFija = new Particle({7,80,7}, {0,0,0}, {0,0,0}, 1, 30000, cube, {0,1,0,1}, 1);
	_particles.push_back(pFija);*/
	auto aGen = new AnchoredSpringForceGenerator(50, 20, { 0,0,0 });

	Particle* pMuelle = new Particle({ 0,15,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,0,1 }, 2, SPHERE, 4);
	_particles.push_back(pMuelle);

	//springGen_= new SpringForceGenerator(1,5,pFija);
	GravityForceGenerator* gGen = new GravityForceGenerator({ 0.0, -9.8, 0.0 });

	//windForceGen = new WindForceGenerator(-1, 0, Vector3(-10, 0, -10), { 7,50,7 }, 20);

	pFR->addRegistry(aGen, pMuelle);
	pFR->addRegistry(gGen, pMuelle);
	//pFR->addRegistry(windForceGen, pMuelle);

}

void ParticleSystem::muelleDoble()
{
	Particle* p1 = new Particle({ 0,15,0 }, { 0,0,0 }, { 0,0,0 }, 0.4, -1, { 0,255,0,1 }, 2, SPHERE, 4);
	_particles.push_back(p1);

	Particle* p2 = new Particle({ 0,15,0 }, { 0,0,0 }, { 0,0,0 }, 0.4, -1, { 0,255,0,1 }, 2, SPHERE, 4);
	_particles.push_back(p2);

	auto f1 = new SpringForceGenerator(50, 20, p2);
	pFR->addRegistry(f1, p1);

	auto f2 = new SpringForceGenerator(50, 20, p1);
	pFR->addRegistry(f2, p2);

	GravityForceGenerator* gGen1 = new GravityForceGenerator({ 1.5, 0, 0.0 });
	pFR->addRegistry(gGen1, p1);

	GravityForceGenerator* gGen2 = new GravityForceGenerator({ -1.5, 0, 0.0 });
	pFR->addRegistry(gGen2, p2);


}


void ParticleSystem::bungee()
{

}

void ParticleSystem::createBuoyancyTest()
{

	auto objetoFlotante = new Particle({ 7,60,7 }, { 0,0,0 }, { 0,0,0 }, 0.9, -1, { 0,0,255,1 }, 2, SPHERE, 900);
	_particles.push_back(objetoFlotante);

	gravityForceGen = new GravityForceGenerator({ 0,-9.8,0 });
	pFR->addRegistry(gravityForceGen, objetoFlotante);


	buoyancyForceGen = new BuoyancyForceGenerator(10.0, 1, 1000, Vector3(7, 50, 7));
	pFR->addRegistry(buoyancyForceGen, objetoFlotante);

}
void ParticleSystem::createSlinky()
{
	float ini = 70, offset = 8;
	GravityForceGenerator* grav = new GravityForceGenerator({ 0, -2, 0.0 });

	Particle* p1 = new Particle({ 7,ini,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,0,255,1 }, 2, SPHERE, 7);
	_particles.push_back(p1);

	
	Particle* p2 = new Particle({ 7,ini - offset,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,255,1 }, 2, SPHERE, 20);
	_particles.push_back(p2);

	auto f2 = new SpringForceGenerator(60, offset, p1);
	pFR->addRegistry(f2, p2);

	pFR->addRegistry(grav, p2);
	auto d2 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d2, p2);

	Particle* p3 = new Particle({ 7,ini - 2 * offset,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,0,255,1 }, 2, SPHERE, 14);
	_particles.push_back(p3);

	auto f3 = new SpringForceGenerator(60, offset, p2);
	pFR->addRegistry(f3, p3);

	pFR->addRegistry(grav, p3);
	auto d3 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d3, p3);


	Particle* p4 = new Particle({ 7,ini - 3 * offset,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,255,255,1 }, 2, SPHERE, 18);
	_particles.push_back(p4);

	auto f4 = new SpringForceGenerator(60, offset, p3);
	pFR->addRegistry(f4, p4);

	pFR->addRegistry(grav, p4);
	auto d4 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d4, p4);


	Particle* p5 = new Particle({ 7,ini - 4 * offset,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,0,0,1 }, 2, SPHERE, 20);
	_particles.push_back(p5);

	auto f5 = new SpringForceGenerator(60, offset, p4);
	pFR->addRegistry(f5, p5);

	pFR->addRegistry(grav, p5);
	auto d5 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d5, p5);


	Particle* p6 = new Particle({ 7,ini - 5 * offset,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,0,1 }, 2, SPHERE, 1);
	_particles.push_back(p6);

	auto f6 = new SpringForceGenerator(60, offset, p5);
	pFR->addRegistry(f6, p6);

	pFR->addRegistry(grav, p6);

	auto d6 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d6, p6);


}