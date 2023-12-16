#pragma once
#include <string>
#include "Particle.h"
class ForceGenerator
{
public:
	virtual void updateForce(Particle* particle, double duration) = 0;
	virtual void updateForceRB(physx::PxRigidDynamic* particle, double duration) = 0;

	std::string _name;
	double t = -1e10; //eterno si es neg

protected:
	int type_;
};