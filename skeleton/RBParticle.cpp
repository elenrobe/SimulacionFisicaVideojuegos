#include "RBParticle.h"
#include <iostream>

RBParticle::RBParticle(Vector3 Pos, Vector3 lVel, Vector3 aVel, double damping, double lifeTime, Vector4 color, double scale, physx::PxPhysics* gPhysics, physx::PxScene* gScene, physx::PxShape* geomShape, bool isStatic, int mass)
{
	this->gScene = gScene;
	this->gPhysics = gPhysics;
	pos = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	this->mass = mass;
	this->isStatic = isStatic;
	this->lVel = lVel;
	this->aVel = aVel;

	if (isStatic) {
		staticR = gPhysics->createRigidStatic(pos);
		physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(scale, scale, scale));
		staticR->attachShape(*geomShape); //Se enlaza la caja con un solido rigido
		gScene->addActor(*staticR); //Se añade el solido rigido a la escena
		//Pintar el suelo
		rI = new RenderItem(geomShape, staticR, color);
		this->lVel = { 0,0,0 };
		this->aVel = { 0,0,0 };
	}
	else {
		dynamicR = gPhysics->createRigidDynamic(pos);
		dynamicR->setLinearVelocity(lVel);
		dynamicR->setAngularVelocity(aVel);
		physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(scale, scale, scale));
		dynamicR->attachShape(*geomShape);
		PxRigidBodyExt::updateMassAndInertia(*dynamicR, mass);
		gScene->addActor(*dynamicR);
		//Pintar el nuevo solido rigido dinamico
		rI = new RenderItem(geomShape, dynamicR, color);
	}
}

void RBParticle::integrate(double t)
{

}
