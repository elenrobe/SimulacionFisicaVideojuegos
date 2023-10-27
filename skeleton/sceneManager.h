#pragma once

#include <vector>

#include "Projectile.h"
#include "ParticleSystem.h"
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
	
	ParticleSystem* pSym;
	void createParticleSystem();


public:
	SceneManager();
	~SceneManager();

	void toDelete();


	void initScene();
	void integrate(double t);
	void shoot(char key);
	void keyPressed(char key);

	//proyectiles
	//a = cte
	//v inicial = v L-l + a*t
	//Pos L = aporximadamente a P L-l + v L+l *t

	/*cam getcamera en constructor
	vector3 vel = cam-> getdir


		en el update del scene manager mirar si hay toDelete */
};

