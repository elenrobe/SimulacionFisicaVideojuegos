
#pragma once

#include "RenderUtils.hpp"

enum ParticleType
{
	SPHERE, FIREWORK
};
class Particle
{

public:
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, Vector4 Color = { 255, 255, 255, 1 });
	Particle(ParticleType Type, Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping);
	Particle(Vector3 Pos, Vector3 Vel, Vector3 Acc, double damping, double lifeTime, Vector4 color, double scale, ParticleType type = ParticleType::SPHERE);
	Particle() {};

	~Particle();
	void integrate(double t);

	virtual Particle* clone() const;
	virtual std::vector<Particle*> explode();

	void setColor(Vector4 newColor) {rI->color = newColor;};
	void setVel(Vector3 newVel) { vel = newVel; };
	void setPos(Vector3 newPos) { pos.p = newPos; };
	void setAcc(Vector3 newAcc) { acc = newAcc; }
	void setMass(float newMass) { mass = newMass; }
	void setDamping(float newDamping) { damping = newDamping; };
	void setMaxDistance(float newDistance) { maxDistance = newDistance; };

	void kill() { alive = false; };

	physx::PxTransform getPos() { return pos; };
	Vector4 getColor() { return color; };
	Vector3 getAcc() { return acc; };
	Vector3 getVel() { return vel; };
	bool getAlive() { return alive; };
	ParticleType getType() { return type; }



protected:
	Vector3 vel;
	physx::PxTransform pos; // A render item le pasaremos la direccion de este pos, para que se actualice automaticamente
	RenderItem* rI;
	Vector3 acc;
	float damping = 0.998f;
	Vector4 color;
	float mass = 1.0f;
	double scale;
	float gravity;
	float tiempoVida;
	float maxDistance;
	Vector3 initPos;
	double initTime;

	bool alive = true;
	ParticleType type;

};

