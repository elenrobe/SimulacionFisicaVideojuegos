#include "Particle.h"

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
	maxDistance = 100;
	initPos = Pos;
}

Particle::Particle(ParticleType Type, Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping)
	: type(Type), pos(Pos), vel(Vel), acc(Acc), damping(Damping)
{
}

Particle::~Particle()
{
	if (rI != nullptr) rI->release();
	//delete  rI;
}

void Particle::integrate(double t)
{
	
	pos.p += vel * t;

	vel = vel * pow(damping, t) + acc * t;


	if (tiempoVida > 0) {
		tiempoVida--;
	}
	else alive = false;

	//Vector3 currentPosChange = { initPos.x + pos.p.x, initPos.y + pos.p.y, initPos.z + pos.p.z };
	//Vector3 maxChange = { maxDistance, maxDistance, initPos.z + pos.p.z };

	if (pos.p.z > maxDistance || pos.p.z < -maxDistance ||
		pos.p.x > maxDistance || pos.p.x < -maxDistance
		|| pos.p.y < 0) alive = false;


}

Particle* Particle::clone() const
{
	Particle* p = new Particle(pos.p, vel, acc, color);
	return p;
}