#include "RBParticleSystem.h"

RBParticleSystem::RBParticleSystem()
{
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(6, 6, 6));

	_particles.push_back(new RBParticle({ 0,50,0 }, { 0,3,0 }, { 2,0,0 }, 0.998, 600, { 0,0,255,1 },5,shape));
	


}
