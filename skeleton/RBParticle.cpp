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
	shape = geomShape;
	this->color = color;
	tiempoVida = lifeTime;
	if (isStatic) {
		staticR = gPhysics->createRigidStatic(pos);
		staticR->attachShape(*geomShape);
		gScene->addActor(*staticR); 
		rI = new RenderItem(geomShape, staticR, color);
		
	}
	else {
		dynamicR = gPhysics->createRigidDynamic(pos);
		dynamicR->setLinearVelocity(lVel);
		dynamicR->setAngularVelocity(aVel);
		dynamicR->attachShape(*geomShape);
		PxRigidBodyExt::updateMassAndInertia(*dynamicR, mass);
		gScene->addActor(*dynamicR);
		rI = new RenderItem(geomShape, dynamicR, color);
	}
}

RBParticle::~RBParticle()
{
	DeregisterRenderItem(rI);

}

void RBParticle::integrate(double t)
{

	if (tiempoVida == -1) {}
	else if (tiempoVida > 0) {
		tiempoVida--;

	}
	else {
		alive = false;
		//std::cout<< alive << std::endl;
	}

}

RBParticle* RBParticle::clone() const
{
	RBParticle* p = new RBParticle(pos.p, lVel,aVel, damping, tiempoVida, color, scale, gPhysics, gScene, shape, isStatic, mass);
	return p;
}
