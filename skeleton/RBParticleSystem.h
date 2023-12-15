#pragma once
#include "RBParticle.h"

class RBParticleSystem
{

	std::vector<RBParticle*> _particles;

public:
	RBParticleSystem();
	~RBParticleSystem();
	void update(double t);

};

