#include "RBParticle.h"

RBParticle::RBParticle(Vector3 Pos, Vector3 lVel, Vector3 aVel, double damping, double lifeTime, Vector4 color, double scale, physx::PxShape* geomShape, bool isStatic, int mass)
{
	this->gScene = gScene;
	this->gPhysics = gPhysics;
	pos = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	this->mass = mass;

	if (isStatic) {
		staticR = gPhysics->createRigidStatic(pos);
		physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(scale, scale, scale));
		staticR->attachShape(*shape); //Se enlaza la caja con un solido rigido
		gScene->addActor(*staticR); //Se a�ade el solido rigido a la escena
		//Pintar el suelo
		rI = new RenderItem(shape, staticR, color);
		this->lVel = { 0,0,0 };
		this->aVel = { 0,0,0 };
	}
	else {
		dynamicR = gPhysics->createRigidDynamic(pos);
		dynamicR->setLinearVelocity(lVel);
		dynamicR->setAngularVelocity(aVel);
		physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(scale, scale, scale));
		dynamicR->attachShape(*shape);
		PxRigidBodyExt::updateMassAndInertia(*dynamicR, (mass));
		gScene->addActor(*dynamicR);
		//Pintar el nuevo solido rigido dinamico
		rI = new RenderItem(shape, dynamicR, color);
	}
}
