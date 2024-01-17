#include "RBProjectile.h"

RBProjectile::RBProjectile(TYPE currentShotType, physx::PxPhysics* gPhysics, physx::PxScene* gScene) : RBParticle(GetCamera()->getEye(), GetCamera()->getDir(), GetCamera()->getDir(), 0.998,300,{1,1,1,1},1,gPhysics,gScene, CreateShape(physx::PxSphereGeometry(1.0f)), false)
{
	dynamicR->setName("bola");
	Vector3 const dir = GetCamera()->getDir();
	switch (currentShotType)
	{
	case PISTOL:
		setMass(2.0f); // 2.0 Kg
		setVel(dir * 35); // 35 m/s
		setAcc(Vector3(0, -1.0f, 0));
		setColor({ 255, 255, 255, 1 });
		break;
	case ARTILLERY:
		setMass(900.0f); // 200.0 Kg
		setVel(dir * 30);
		setAcc(Vector3(0.0f, -20.0f, 0.0f));
		setColor({ 0, 0, 0, 1 });

		break;
	}
}
