#include "particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, Vector4 Color)
{
	vel = Vel;
	acc = Acc;
	pos = physx::PxTransform(Pos);
	damping = 0.998;
	physx::PxSphereGeometry sphere(1);
	physx::PxShape* shape
		=
		CreateShape(sphere);
	color = Color;
	rI = new RenderItem(shape, &pos, color);
	alive = true;
	tiempoVida = 1000;
}

Particle::~Particle()
{
	if (rI != nullptr) rI->release();
}

void Particle::integrate(double t)
{
	pos.p += vel * t;

	vel += acc * t;

	vel *= powf(damping, t); //dumping elevado a t


	if (tiempoVida > 0) {
		tiempoVida--;
	}
	else alive = false;


}
