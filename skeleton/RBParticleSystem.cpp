#include "RBParticleSystem.h"


RBParticleSystem::RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{

	rb_pFR = std::make_unique<RBParticleForceRegistry>();
	addWind();
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(4, 4, 4));
	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(100, 1, 100));
	RBParticle* p = new RBParticle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, 600, { 0,0,255,1 }, 5, gPhysics, gScene, shape, false, 17850);
	_particles.push_back(p);
	
	_particles.push_back(new RBParticle({ 0,0,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, 600, { 0,0,0,1 }, 5, gPhysics, gScene, floor, 900));

	//rb_pFR.get()->addRegistry(windForceGen, p->getDynamicRigid());

}

void RBParticleSystem::update(double t)
{

	rb_pFR.get()->updateForces(t);
	//_particles[0]->addForce({ 0,1,0 });
	//std::cout << _particles[0]->returnForce().x << _particles[0]->returnForce().y << _particles[0]->returnForce().z;
}

void RBParticleSystem::generateParticles()
{
}

void RBParticleSystem::addWind()
{
	windForceGen = new WindForceGenerator(-1, 0, Vector3(100, 100, 100), { 0,10,0 }, 400);

}
