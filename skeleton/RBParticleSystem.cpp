#include "RBParticleSystem.h"

RBParticleSystem::RBParticleSystem(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(6, 6, 6));
	physx::PxShape* floor = CreateShape(physx::PxBoxGeometry(100, 1, 100));

	_particles.push_back(new RBParticle({ 0,50,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, 600, { 0,0,255,1 },5, gPhysics,gScene,shape, false));
	
	_particles.push_back(new RBParticle({ 0,0,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, 600, { 0,0,0,1 }, 5, gPhysics, gScene, floor));


}

void RBParticleSystem::update(double t)
{
}
