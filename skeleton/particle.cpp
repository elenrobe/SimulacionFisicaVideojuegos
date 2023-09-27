#include "particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel)
{
	vel = { Vel.x, Vel.y, Vel.z };
	pose = physx::PxTransform(Pos);
	physx::PxSphereGeometry sphere(3);
	physx::PxShape* shape
		=
		CreateShape(sphere);
	const Vector4 color = { 255, 255, 255, 1 }; rI = new RenderItem(shape, &pose, color);
		
}

Particle::~Particle()
{
	if (rI != nullptr) rI->release();
}

void Particle::integrate(double t)
{
	pose.p += vel * t;
}
