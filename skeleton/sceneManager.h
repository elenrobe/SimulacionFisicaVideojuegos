#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>
#include "particle.h"
#include "proyectil.h"

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

