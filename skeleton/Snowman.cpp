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

	if (numHits < 3) {

		if (numHits == 0) {
			bola2 = new RBParticle({ bola1->getPos().p.x,bola1->getPos().p.y +3,bola1->getPos().p.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,1,1 }, 5, gPhysics, gScene, bolaShape, false, 200);

			bola2->getDynamicRigid()->setName("snowman");

			numHits++;
			particles.push_back(bola2);


		}
		else if (numHits == 1) {
			eye1 = new RBParticle({ pos.x,pos.y+20,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,1,1 }, 5, gPhysics, gScene, bolaShape, false, 200);

			eye1->getDynamicRigid()->setName("snowman");
			particles.push_back(eye1);
			numHits++;

		}
		else if (numHits == 2) {
			eye2->getDynamicRigid()->setName("snowman");
			particles.push_back(eye2);
			numHits++;

		}
		
	}
}
