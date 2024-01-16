#pragma once
#include "RenderUtils.hpp"
#include "core.hpp"
using namespace physx;

class RBParticle
{
	public:
		RBParticle(Vector3 Pos, Vector3 lVel, Vector3 aVel, double damping, double lifeTime, Vector4 color, double scale, physx::PxPhysics* gPhysics, physx::PxScene* gScene, physx::PxShape* geomShape, bool isStatic = true, int mass = 1);


		~RBParticle();
		void integrate(double t);


		physx::PxRigidDynamic* getDynamicRigid() { return dynamicR; }
		physx::PxRigidStatic* getStaticRigid() { return staticR; }

		void setColor(Vector4 newColor) { rI->color = newColor; };
		void setPos(Vector3 newPos) { pos.p = newPos; };
		void setAcc(Vector3 newAcc) { acc = newAcc; }
		void setMass(float newMass) { mass = newMass; }

		void kill() { alive = false; };
		virtual RBParticle* clone() const;

		void addForce(Vector3 f) {
			if(!isStatic)dynamicR->addForce(f);
		}
		void clearAccum() {
			if (!isStatic)dynamicR->clearForce();
		}

		Vector3 returnForce() { return _force_accum; };


		physx::PxTransform getPos() { return pos; };
		Vector4 getColor() { return color; };
		Vector3 getAcc() { return acc; };
		bool getAlive() { return alive; };
		double getMass() { return mass; };
		double getInverseMass() { return 1 / mass; };
		bool getIsStatic() { return isStatic; };


	protected:
		Vector3 lVel; //Velocidad lineal
		Vector3 aVel; //velocidad angular
		physx::PxTransform pos; // A render item le pasaremos la direccion de este pos, para que se actualice automaticamente
		RenderItem* rI;
		Vector3 acc;
		Vector4 color;
		double scale;
		float tiempoVida;
		float maxDistance;
		Vector3 initPos;
		double initTime;

		bool alive = true;
		bool isStatic = true;
		
		double size;

		physx::PxRigidStatic* staticR;
		physx::PxRigidDynamic* dynamicR;

		physx::PxShape* shape;
		physx::PxPhysics* gPhysics;
		physx::PxScene* gScene;

		// Accumulated force
		Vector3 force;
		Vector3 _force_accum;
		double damping, mass, inverse_mass, gravity;



};

