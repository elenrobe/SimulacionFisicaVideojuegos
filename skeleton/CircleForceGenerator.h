#pragma once
#include "WindForceGenerator.h"

class CircleForceGenerator :public ForceGenerator
{
public:
	CircleForceGenerator(Vector3 speed, Vector3 origin, float r);
	virtual void updateForce(Particle* particle, double t) override;
	virtual void updateForceRB(physx::PxRigidDynamic* particle, double t) override;

	~CircleForceGenerator() {};
private:
	Vector3 origin_;
	float varY_, K_;
	float radius;
	float angle;
};