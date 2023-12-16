#include "Particle.h"
#include <iostream>

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
	tiempoVida = 300;
	maxDistance = 100;
	initPos = Pos;
	type = SPHERE;
	this->type = type;
	this->mass = mass;
	inverse_mass = 1 / mass;

	force = { 0,0,0 };
	_force_accum = { 0,0,0 };
	gravity = -9.8;
}

Particle::Particle(ParticleType Type, Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping)
	: type(Type), pos(Pos), vel(Vel), acc(Acc), damping(Damping)
{
}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, double damping, double lifeTime, Vector4 color, double scale, ParticleType type, double mass)
{
	vel = Vel;
	acc = Acc;
	this->damping = damping;
	tiempoVida = lifeTime;
	this->color = color;
	this->scale = scale;
	pos = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	rI = new RenderItem(CreateShape(physx::PxSphereGeometry(scale)), &pos, color);
	alive = true;
	this->type = type;
	this->mass = mass;
	inverse_mass = 1 / mass;

	force = { 0,0,0 };
	_force_accum = { 0,0,0 };
	gravity = -9.8;
}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, double damping, double lifeTime, physx::PxShape* geomShape, Vector4 color, double scale, int mass, int type)
{
	vel = Vel;
	acc = Acc;
	this->damping = damping;
	tiempoVida = lifeTime;
	this->color = color;
	pos = physx::PxTransform(Pos.x, Pos.y, Pos.z);
	rI = new RenderItem(geomShape, &pos, color);
	alive = true;
	this->scale = scale;
	this->mass = mass;
	inverse_mass = 1 / mass;
}

Particle::~Particle()
{
	//if (rI != nullptr) rI->release();
	DeregisterRenderItem(rI);
}

void Particle::integrate(double t)
{
	

	Vector3 resulting_accel = _force_accum * 1/mass;
	vel += resulting_accel * t; // Ex. 1.3 --> add acceleration

	vel *= pow(damping, t); // Exercise 1.3 --> add damping
	pos.p += vel * t;


	if(tiempoVida == -1){}
	else if (tiempoVida > 0) {
		tiempoVida--;
		
	}
	else {
		alive = false;
		//std::cout<< alive << std::endl;
	}

	clearAccum();


}

Particle* Particle::clone() const
{
	Particle* p = new Particle(pos.p, vel, acc, damping, tiempoVida, color, scale, type, mass);
	return p;
}

std::vector<Particle*> Particle::explode()
{
	return std::vector<Particle*>();
}
