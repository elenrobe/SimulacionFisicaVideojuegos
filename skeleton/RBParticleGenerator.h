#pragma once

#include "RBParticle.h"

using namespace std;

class RBParticleGenerator
{
public:

	RBParticleGenerator();
	virtual ~RBParticleGenerator();

	void setParticle(RBParticle* model);
	virtual std::vector<RBParticle*> generateParticles();

	string getName() { return _name; };
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double _generation_probability;
	int _num_particles = 5;
	RBParticle* _model;
};

