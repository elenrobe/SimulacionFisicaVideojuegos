#pragma once
#include "ForceGenerator.h"
class ExplosionForceGenerator :public ForceGenerator
{
public:

	ExplosionForceGenerator(double K, double R, double const_tiempo, Vector3& position);
	virtual void updateForce(Particle* particle, double t) override;
	~ExplosionForceGenerator() {};
	void passTime();
protected:

	Vector3 origin_;
	//intensidad, radio
	double K_, R_, tiempo_;

};