#pragma once

#include "RenderUtils.hpp"
#include "core.hpp"

#include <list>
#include <memory>
#include <random>
#include "Particle.h"
#include "CircleParticleGenerator.h"

class Firework : public Particle
{
public:
	Firework(Vector3 pos, Vector3 vel, Vector3 acc, float damping, double lifeTime, Vector4 color, double scale, double mass, float type)
		: Particle(pos, vel, acc, damping, lifeTime, color, scale, ParticleType::FIREWORK, mass) {
		this->type = type;
	}

	~Firework() {};


	Firework* clone() const;
	vector<Particle*> explode() override;
	ParticleGenerator* addGenerator(ParticleGenerator* p);

protected:
	float type;
	ParticleGenerator* gen;
	list<shared_ptr<ParticleGenerator>> _gens;
};

