#include "Snowman.h"

Snowman::Snowman(Vector3 pos, physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	this->pos = pos;
	this->gPhysics = gPhysics;
	this->gScene = gScene;
	physx::PxShape* bolaShape = CreateShape(physx::PxSphereGeometry(4.0f));

	bola1 = new RBParticle({ pos.x,pos.y,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,1,1 }, 5, gPhysics, gScene, bolaShape, false, 200);

	bola1->getDynamicRigid()->setName("snowman");
	particles.push_back(bola1);


}

void Snowman::crece()
{
	physx::PxShape* bolaShape = CreateShape(physx::PxSphereGeometry(4.0f));
	physx::PxShape* bolaShape2 = CreateShape(physx::PxSphereGeometry(1.0f));

	if (numHits < 1) {

		if (numHits == 0) {
			bola2 = new RBParticle({ bola1->getDynamicRigid()->getGlobalPose().p.x,bola1->getDynamicRigid()->getGlobalPose().p.y + 5,bola1->getDynamicRigid()->getGlobalPose().p.z}, {0,0,0}, {0,0,0}, 0.998, -1, {1,1,1,1}, 5, gPhysics, gScene, bolaShape, false, 200);


			PxRevoluteJoint* joint = PxRevoluteJointCreate(*gPhysics, bola1->getDynamicRigid(), bola1->getDynamicRigid()->getGlobalPose(), bola2->getDynamicRigid(), bola2->getDynamicRigid()->getGlobalPose());
			

			numHits++;
			particles.push_back(bola2);



		}
		else if (numHits == 1) {

			numHits++;

		}
		
	}
}
