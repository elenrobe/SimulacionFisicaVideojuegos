#include "ExplosionForceGenerator.h"
#include <cmath>

ExplosionForceGenerator::ExplosionForceGenerator(double K, double R, double tiempo_, Vector3& position)
{
	origin_ = position;
	K_ = K;
	R_ = R;
	tiempo_ = tiempo_;
}

void ExplosionForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInverseMass() < 1e-10))
		return;

	double r = pow((particle->getPos().p.x - origin_.x), 2) +
		pow((particle->getPos().p.y - origin_.y), 2) +
		pow((particle->getPos().p.z - origin_.z), 2);

	if (r < R_) {

		Vector3 force = (K_ / r) *
			Vector3(particle->getPos().p.x - origin_.x,
				particle->getPos().p.y - origin_.y,
				particle->getPos().p.z - origin_.z)
			* std::expf(-t / const_tiempo_desv_);

		particle->addForce(force);
	}
	R_ += 343 * t; //speed del medio aire
}

void ExplosionForceGenerator::passTime()
{
	const_tiempo_desv_++;
}
