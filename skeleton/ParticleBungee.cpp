#include "ParticleBungee.h"
#include <iostream>
ParticleBungee::ParticleBungee(double k, double resting, Particle* other) :
	SpringForceGenerator(k, resting, other) { }

void ParticleBungee::updateForce(Particle* particle, double t) {

	if (fabs(particle->getInverseMass()) < 1e-10)
		return;

	Vector3 f = particle->getPos().p;
	f -= other_->getPos().p;

	float length = f.normalize();
	length = (length - resting_length);

	if (length > 0) {

		f *= -(length * k_);
		particle->addForce(f);
	}




}
