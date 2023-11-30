#include "BuoyancyForceGenerator.h"
BuoyancyForceGenerator::BuoyancyForceGenerator(float h, float V, float d, Vector3& pos) :height(h), volume(V), liquid_density(d)
{
	_liquid_particle = new Particle(pos, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,0,1 }, 2, SPHERE, 4);
}
void BuoyancyForceGenerator::updateForce(Particle* p, double t) {

	float h = p->getPos().p.y;
	float h0 = _liquid_particle->getPos().p.y;
	Vector3 f(0, 0, 0);
	float immersed = 0.0;

	if (h - h0 > height * 0.5) {
		immersed = 0.0;
	}
	else if (h0 - h > height * 0.5) {
		//Totally immersed
		immersed = 1.0;
	}
	else {
		immersed = (h0 - h) / height + 0.5;
	}

	f.y = liquid_density * volume * immersed * 9.8;
	p->addForce(f);

}