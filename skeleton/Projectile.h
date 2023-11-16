#pragma once
#include "Particle.h"
class Projectile : public Particle
{
public:
	enum TYPE { PISTOL, ARTILLERY, FIREBALL, LASER, BASE };

	Projectile(TYPE type);

	Projectile(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping, float Mass, Vector4 Color = { 255, 255, 255, 1 });

	
	~Projectile();

private:
};

