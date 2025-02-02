#include "WhirlwindForceGenerator.h"

WhirlwindForceGenerator::WhirlwindForceGenerator(const float k1, const float k2,
	float K, Vector3 windVelocity, Vector3 origin, double variabilidadY) : WindForceGenerator(k1, k2, windVelocity, { 0,0,0 }) {
	setDrag(k1, k2);
	windVel_ = windVelocity;
	origin_ = origin;
	varY_ = variabilidadY;
	K_ = K;
	r_ = 400;
};
void WhirlwindForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInverseMass()) < 1e-10)
		return;


	if (insideRadius(particle)) {
		auto x = -(particle->getPos().p.z - origin_.z);
		auto y = varY_ - (particle->getPos().p.y - origin_.y);
		auto z = (particle->getPos().p.x - origin_.x);

		windVel_ = K_ * Vector3(x, y, z);

		Vector3 newVel = particle->getVel() - windVel_;
		float drag_coef = newVel.normalize();

		drag_coef = _k1 * drag_coef + _k2 * drag_coef;
		Vector3 whirlForce = -newVel * drag_coef;

		particle->addForce(whirlForce);

	}
}

void WhirlwindForceGenerator::updateForceRB(physx::PxRigidDynamic* particle, double t)
{

	if (fabs(particle->getInvMass()) < 1e-10)
		return;


		auto x = -(particle->getGlobalPose().p.z - origin_.z);
		auto y = varY_ - (particle->getGlobalPose().p.y - origin_.y);
		auto z = (particle->getGlobalPose().p.x - origin_.x);

		windVel_ = K_ * Vector3(x, y, z);

		Vector3 newVel = particle->getLinearVelocity() - windVel_;
		float drag_coef = newVel.normalize();

		drag_coef = _k1 * drag_coef + _k2 * drag_coef;
		Vector3 whirlForce = -newVel * drag_coef;

		particle->addForce(whirlForce);

}
