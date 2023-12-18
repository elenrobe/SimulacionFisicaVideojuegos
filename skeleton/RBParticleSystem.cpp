#include "RBParticleSystem.h"


RBParticleSystem::RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{

	rb_pFR = std::make_unique<RBParticleForceRegistry>();
	addWind();
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(4));
	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(100, 1, 100));
	RBParticle* p = new RBParticle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,0,255,1 }, 5, gPhysics, gScene, shape, false, 1);
	_particles.push_back(p);

	RBParticle* p2 = new RBParticle({ 0,50,50 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,255,255,1 }, 5, gPhysics, gScene, shape, false, 7000);
	_particles.push_back(p2);
	
	_particles.push_back(new RBParticle({ 0,0,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, 600, { 0,0,0,1 }, 5, gPhysics, gScene, floor, 900));

	//rb_pFR.get()->addRegistry(windForceGen, p->getDynamicRigid());

}

void RBParticleSystem::update(double t)
{

	rb_pFR.get()->updateForces(t);
	
	//for (auto i : _particles) {
	//	if(!i->getIsStatic())
	//		i->getDynamicRigid()->addForce({0,0,100});
	//}
	//std::cout << _particles[0]->returnForce().x << _particles[0]->returnForce().y << _particles[0]->returnForce().z;
}

void RBParticleSystem::generateParticles()
{
}

void RBParticleSystem::addWind()
{
	windForceGen = new WindForceGenerator(-1, 3, Vector3(100, 100, 100), { 0,10,0 }, 400);

}

void RBParticleSystem::addExplosion()
{

	explosionForceGen = new ExplosionForceGenerator(2000, 1000, 400, Vector3(0, 50, 0));

	for (auto p : _particles)
	{ 
		if (!p->getIsStatic()) {
			rb_pFR.get()->addRegistry(explosionForceGen, p->getDynamicRigid());
		}
	}
		

}
