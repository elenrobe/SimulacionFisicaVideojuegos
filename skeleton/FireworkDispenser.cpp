#include "FireworkDispenser.h"

FireworkDispenser::FireworkDispenser(Vector3 pos, physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(1, 40, 15));
	RBParticle* base = new RBParticle({ pos.x,pos.y,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,0,0,1 }, 5, gPhysics, gScene, shape, true, 100);

}
