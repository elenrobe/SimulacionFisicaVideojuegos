#pragma once

#include <vector>

#include "Projectile.h"
#include "ParticleSystem.h"
#include "RBParticleSystem.h"
class SceneManager
{
private:
	Particle* xAxis;
	Particle*  yAxis;
	Particle* zAxis;
	Particle* centerAxis;

	Camera* cam;
	void createAxis();

	std::vector<Particle*> proyectiles;

	RBParticleSystem* rb_pSym;
	ParticleSystem* pSym;
	void createParticleSystem();


public:
	SceneManager();
	SceneManager(physx::PxPhysics* gPhysics, physx::PxScene* gScene);

	~SceneManager();

	void toDelete();


	void initScene();
	void integrate(double t);
	void shoot(char key);
	void keyPressed(char key);

	void initSceneRB();

};

