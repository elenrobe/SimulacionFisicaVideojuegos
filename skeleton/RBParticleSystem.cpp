#include "RBParticleSystem.h"


RBParticleSystem::RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	this->gPhysics = gPhysics;
	this->gScene = gScene;

	rb_pFR = std::make_unique<RBParticleForceRegistry>();
	
	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(100, 1, 100));
	_particles.push_back(new RBParticle({ 0,-100,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, -1, { 0,0,0,1 }, 5, gPhysics, gScene, floor, 900));

	//INICIALIZAR LOS FORCE GENERATORS
	windForceGen = new WindForceGenerator(-1, 3, Vector3(200, 0, 0), { 0,10,0 }, 400);
	addWhirlwind();

	Noria* noria = new Noria(gPhysics, gScene);
}

void RBParticleSystem::update(double t)
{
	for (auto g : _particle_generators)
	{
		auto v = g->generateParticles();

		//std::vector<ForceGenerator*> force = g->returnForce();

		for (RBParticle* p : v)
		{
			_particles.push_back(p);

			if (!p->getIsStatic()) {


				if (windOn)
					rb_pFR.get()->addRegistry(windForceGen, p->getDynamicRigid());

				if (whirlwindOn) {
					rb_pFR.get()->addRegistry(whirlwindForceGen, p->getDynamicRigid());

				}
			}


		}
	}

	// integrate de cada particula
	for (int i = 0; i < _particles.size(); i++) {


		_particles[i]->integrate(t);
		if (!_particles[i]->getAlive()) {


			//cout << "dead";

			rb_pFR.get()->deleteParticleRegistry(_particles[i]->getDynamicRigid());
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		}
	}
	rb_pFR.get()->updateForces(t);
	
}

void RBParticleSystem::generateParticles()
{
	//physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(4));
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(4, 4, 4));

	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(100, 1, 100));
	RBParticle* p = new RBParticle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,0,255,1 }, 5, gPhysics, gScene, shape, false, 1);
	_particles.push_back(p);

	RBParticle* p2 = new RBParticle({ 0,50,50 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,255,1 }, 5, gPhysics, gScene, shape, false, 7000);
	_particles.push_back(p2);

	_particles.push_back(new RBParticle({ 0,0,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, -1, { 0,0,0,1 }, 5, gPhysics, gScene, floor, 900));

	//rb_pFR.get()->addRegistry(windForceGen, p->getDynamicRigid());
}

void RBParticleSystem::deleteAll()
{
	for (int i = 0; i < _particles.size(); i++) {




			rb_pFR.get()->deleteParticleRegistry(_particles[i]->getDynamicRigid());
			delete _particles[i];
			_particles.erase(_particles.begin() + i);
		
	}

}

void RBParticleSystem::createManguerSystem()
{

	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(1, 1, 1));
	RBParticle* p = new RBParticle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, 100, { 255,255,255,1 }, 5, gPhysics, gScene, shape, false, 1);

	RBUniformParticleGenerator* uniformGenerator = new RBUniformParticleGenerator({ 5, 0, 5 }, { 0, 30, 0 }, 1, p, { 1,1,1 }, { 6,20,6 });

	_particle_generators.push_back(uniformGenerator);
}

void RBParticleSystem::addWind()
{

	//for (auto p : _particles)
	//{
	//	if (!p->getIsStatic()) {
	//		rb_pFR.get()->addRegistry(windForceGen, p->getDynamicRigid());
	//	}
	//}
}

void RBParticleSystem::addWhirlwind()
{
	whirlwindForceGen = new WhirlwindForceGenerator(1, 0, 1.0, Vector3(9, 9, 9), { 7,50,7 }, 100);


}

void RBParticleSystem::addExplosion()
{

	explosionForceGen = new ExplosionForceGenerator(40, 1000, 1, Vector3(0, 20, 0));

	for (auto p : _particles)
	{ 
		if (!p->getIsStatic()) {
			rb_pFR.get()->addRegistry(explosionForceGen, p->getDynamicRigid());
		}
	}
		

}
