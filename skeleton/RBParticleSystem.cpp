#include "RBParticleSystem.h"


RBParticleSystem::RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	this->gPhysics = gPhysics;
	this->gScene = gScene;

	rb_pFR = std::make_unique<RBParticleForceRegistry>();
	generateFinalScene();
	
	//INICIALIZAR LOS FORCE GENERATORS
	/*windForceGen = new WindForceGenerator(-1, 3, Vector3(200, 0, 0), { 0,10,0 }, 400);
	addWhirlwind();*/

}

void RBParticleSystem::generateFinalScene()
{
	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(400, 1, 400));
	_particles.push_back(new RBParticle({ 0,-80,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, -1, { 1,1,1,1 }, 5, gPhysics, gScene, floor, 900));

	generateNoria();
	generateSnowman();
	//generateParticles();

	//buoyancy

	//auto objetoFlotante = new Particle({ 7,60,7 }, { 0,0,0 }, { 0,0,0 }, 0.9, -1, { 0,0,255,1 }, 2, SPHERE, 900);
	//_particles.push_back(objetoFlotante);


	//buoyancyForceGen = new BuoyancyForceGenerator(10.0, 1, 1000, Vector3(7, 50, 7));
	//pFR->addRegistry(buoyancyForceGen, objetoFlotante);

	/*physx::PxShape* B = CreateShape(physx::PxBoxGeometry(2, 2, 2));
	RBParticle* r = new RBParticle({ 7,60,7 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 5, gPhysics, gScene, B, false, 900);
	_particles.push_back(r);


	buoyancyForceGen = new BuoyancyForceGenerator(10.0, 1, 1000, Vector3(7, 50, 7));
	rb_pFR->addRegistry(buoyancyForceGen, r->getDynamicRigid());*/
}

void RBParticleSystem::generateNoria()
{
	Noria* noria = new Noria(Vector3(-200, 0, 0), gPhysics, gScene);
	
	auto v = noria->getParticles();

	for (RBParticle* p : v)
	{
		_particles.push_back(p);


	}

}

void RBParticleSystem::generateSnowman()
{
	for (int i = 0; i < 3; i++) {
		float z = 30 * i;
		Snowman* s = new Snowman(Vector3(-100, 10, z), gPhysics, gScene);

		auto v = s->getParticles();

		for (RBParticle* p : v)
		{
			_particles.push_back(p);


		}
		_snowmen.push_back(s);
	}
}

void RBParticleSystem::shootBullet()
{
	RBProjectile* p = new RBProjectile(RBProjectile::PISTOL, gPhysics, gScene);

	_particles.push_back(p);

}


void RBParticleSystem::checkCollisions(physx::PxActor* snowman, physx::PxActor* actor2)
{
	
	for (int i = 0; i < _snowmen.size(); i++) {
		if (_snowmen[i]->getBola1()->getDynamicRigid() == snowman) {
			int numHits = _snowmen[i]->getHits();
			_snowmen[i]->crece();
			if (numHits == 0) {
				_particles.push_back(_snowmen[i]->getBola2());

			}
			/*Vector3 pos = _snowmen[i]->getBola1()->getDynamicRigid()->getGlobalPose().p;
			physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(2, 1, 2));
			_particles.push_back(new RBParticle(pos, { 0,3,0 }, { 2,0,0 }, 0.998, -1, { 0,1,1,1 }, 5, gPhysics, gScene, floor, false, 900));
*/

		}
	}
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

	explosionForceGen = new ExplosionForceGenerator(60, 500, 1, Vector3(0, 0, 0));

	for (auto p : _particles)
	{ 
		if (!p->getIsStatic()) {
			rb_pFR.get()->addRegistry(explosionForceGen, p->getDynamicRigid());
		}
	}
		

}
