#pragma once
#include "RenderUtils.hpp"
class Particle
{

public:
	Particle(Vector3 Pos, Vector3 Vel);
	~Particle();
	void integrate(double t);
private:
	Vector3 vel;
	physx::PxTransform pose; // A render item le pasaremos la direccion de este pose, para que se actualice automaticamente
	RenderItem* renderItem;
};

