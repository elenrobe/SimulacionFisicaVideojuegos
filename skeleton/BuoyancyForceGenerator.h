#pragma once
#include "ForceGenerator.h"
class BuoyancyForceGenerator :public ForceGenerator
{
public:
	BuoyancyForceGenerator(float h, float V, float d, Vector3& pos);
	virtual void updateForce(Particle* particle, double t);
	virtual void updateForceRB(physx::PxRigidDynamic* particle, double t) override;

	virtual ~BuoyancyForceGenerator() { };
protected:
	float height;
	float volume;
	float liquid_density;
	float gravity = 9.8;
	Particle* _liquid_particle; // For representation
};