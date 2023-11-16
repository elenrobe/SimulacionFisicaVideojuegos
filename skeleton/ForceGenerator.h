#pragma once
#include <string>
#include "Particle.h"
class ForceGenerator
{
public:
	virtual void updateForce(Particle* particle, double duration) = 0;
	std::string _name;
	double t = -1e10; //eterno si es neg
	enum forceTypes { NONE, GRAVITY, WIND, WHIRLWIND, EXPLOSION };
	forceTypes forceType = NONE;

protected:
	int type_;
};