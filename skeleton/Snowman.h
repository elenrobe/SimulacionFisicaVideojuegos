#pragma once
#include "RBParticle.h"
#include <iostream>
#include <random>
class Snowman
{
	RBParticle* bola1;
	RBParticle* bola2;

	std::vector<RBParticle*> particles;
	int numHits = 0;
	Vector3 pos;

	physx::PxPhysics* gPhysics;
	physx::PxScene* gScene;

public:
	Snowman(Vector3 pos, physx::PxPhysics* gPhysics, physx::PxScene* gScene);

	~Snowman();
	std::vector<RBParticle*> getParticles() {
		return particles;
	}

	RBParticle* getBola1() { return bola1; };
	RBParticle* getBola2() { return bola2; };

	int getHits() { return numHits; };
	void crece();
};

