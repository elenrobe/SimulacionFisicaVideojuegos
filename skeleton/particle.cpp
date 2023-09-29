#include "particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping)
{
	vel = Vel;
	acc = Acc;
	damping = Damping;
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

	vel += acc * t;

	vel *= powf(damping, t); //dumping elevado a t
}
