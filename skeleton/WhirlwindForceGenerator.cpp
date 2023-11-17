#include "WhirlwindForceGenerator.h"

WhirlwindForceGenerator::WhirlwindForceGenerator(const float k1, const float k2,
	float K, Vector3 windVelocity, Vector3 origin) : WindForceGenerator(k1, k2, windVelocity, { 0,0,0 }) {
	setDrag(k1, k2);
	windVel_ = windVelocity;
	origin_ = origin;
	varY_ = 50;
	K_ = K;
};
void WhirlwindForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInverseMass()) < 1e-10)
		return;

	auto x = -(particle->getPos().p.z - origin_.z);
	auto y = varY_ - (particle->getPos().p.y - origin_.y);
	auto z = (particle->getPos().p.x - origin_.x);

	windVel_ = K_ * Vector3(x, y, z);

	Vector3 v = particle->getVel() - windVel_;
	float drag_coef = v.normalize();

	Vector3 dragF;
	drag_coef = _k1 * drag_coef + _k2 * drag_coef * drag_coef;
	dragF = -v * drag_coef;

	particle->addForce(dragF);

}