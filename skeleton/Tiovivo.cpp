#include "Tiovivo.h"

Tiovivo::Tiovivo(Vector3 pos, std::unique_ptr<ParticleForceRegistry>&  pFR)
{
	
	//auto objetoFlotante = new Particle({ 7,90,7 }, { 0,0,0 }, { 0,0,0 }, 1, -1, { 0,255,255,1 }, 2, SPHERE, 200);
	//particles.push_back(objetoFlotante);

	//gravityForceGen = new GravityForceGenerator({ 0,-9.8,0 });
	//pFR->addRegistry(gravityForceGen, objetoFlotante);


	//buoyancyForceGen = new BuoyancyForceGenerator(10.0, 1, 1000, Vector3(7, 50, 7));
	//pFR->addRegistry(buoyancyForceGen, objetoFlotante);

	//c = new CircleForceGenerator({ 7,60,7 }, { 7,60,7 }, 200);
	//pFR->addRegistry(c, objetoFlotante);

	//s = new SpringForceGenerator({ 7,60,7 }, { 7,60,7 }, 200);
	//pFR->addRegistry(c, objetoFlotante);




	float ini = pos.y, offset = 8;

	GravityForceGenerator* grav = new GravityForceGenerator({ 0, -2, 0.0 });

	//Particle* p1 = new Particle({ 7,ini,7 }, { 0,0,0 }, { 0,0,0 }, 1, -1, cube, { 0,1,0,1 }, 1);
	float radio = 100;
	for (int i = 0; i < 6; i++) {
		float angle = i * 2.0f * physx::PxPi / 12;
		float x = pos.x + 0;

		//float y = 0;
		//float z = cabinRadius * std::sin(angle);
		float y = pos.y + radio / 3 * 2 * std::sin(angle);
		float z = pos.z + radio / 3 * 2 * std::cos(angle);

		Particle* p0 = new Particle({ pos.x,ini - offset * 4,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,255,0,1 }, 1.1, BARRA, 20);

		particles.push_back(p0);

		Particle* p1 = new Particle({ pos.x,ini - offset,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,255,0,1 }, 5, TIOVIVO, 20);

		particles.push_back(p1);

		Particle* p2 = new Particle({ pos.x,ini - offset * 2,pos.z }, { 0,0,0 }, { 0,0,0 }, 1, -1, { 0,255,255,1 }, 4, HORSE, 20);

		particles.push_back(p2);

		auto f2 = new SpringForceGenerator(30, offset * 2, p1);
		pFR->addRegistry(f2, p2);

		pFR->addRegistry(grav, p2);
		auto d2 = new ParticleDragGenerator(0.8, 0.8);
		pFR->addRegistry(d2, p2);
	}



}
