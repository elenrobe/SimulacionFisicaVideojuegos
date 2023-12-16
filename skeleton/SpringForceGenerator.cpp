#include "SpringForceGenerator.h"

void SpringForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInverseMass()) < 1e-10)
		return;

	Vector3 force = other_->getPos().p - particle->getPos().p;
	const float length = force.normalize();
	const float delta_x = length - resting_length;

	force *= delta_x * k_;
	particle->addForce(force);
}

void SpringForceGenerator::updateForceRB(physx::PxRigidDynamic* particle, double t)
{
	if (fabs(particle->getInvMass()) < 1e-10)
		return;

	Vector3 force = other_->getPos().p - particle->getGlobalPose().p;
	const float length = force.normalize();
	const float delta_x = length - resting_length;

	force *= delta_x * k_;
	particle->addForce(force);
}
