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


	Particle* p0 = new Particle({ pos.x,ini - offset*4,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,255,0,1 }, 1.1, BARRA, 20);

	particles.push_back(p0);

	Particle* p1 = new Particle({ pos.x,ini - offset,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,255,0,1 }, 5, TIOVIVO, 20);

	particles.push_back(p1);

	Particle* p2 = new Particle({ pos.x,ini - 2 * offset,pos.z }, { 0,0,0 }, { 0,0,0 }, 1, -1, { 0,255,255,1 }, 4, SPHERE, 30);

	particles.push_back(p2);

	auto f2 = new SpringForceGenerator(60, offset, p1);
	pFR->addRegistry(f2, p2);

	pFR->addRegistry(grav, p2);
	auto d2 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d2, p2);

	Particle* p3 = new Particle({ pos.x,ini - offset *2,pos.z }, { 0,0,0 }, { 0,0,0 }, 1, -1, { 0,255,255,1 }, 4, HORSE, 20);
	particles.push_back(p3);

	auto f3 = new SpringForceGenerator(60, offset, p2);
	pFR->addRegistry(f3, p3);

	pFR->addRegistry(grav, p3);
	auto d3 = new ParticleDragGenerator(0.8, 0.8);
	pFR->addRegistry(d3, p3);


}
