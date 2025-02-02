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
	float radio = 40;
	int num = 6;
	for (int i = 0; i < num; i++) {
		GravityForceGenerator* grav = new GravityForceGenerator({ 0, -2, 0.0 });

		float angle = i * 2.0f * physx::PxPi / num;
		float x = pos.x + radio * std::sin(angle);
		//float y = 0;
		//float z = cabinRadius * std::sin(angle);
		float y = pos.y;
		float z = pos.z + radio * std::cos(angle);

		Particle* p0 = new Particle({ x,ini - offset * 4,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 1.1, BARRA, 20);

		particles.push_back(p0);

		Particle* base1 = new Particle({ x,ini,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 30, BASE, 20);

		particles.push_back(base1);

		Particle* base2 = new Particle({ x,ini-60,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 30, BASE, 20);

		particles.push_back(base2);

		Particle* p1 = new Particle({ x,ini - offset,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 5, TIOVIVO, 20);

		particles.push_back(p1);


		auto aGen = new AnchoredSpringForceGenerator(50, 20, { x,ini - offset,z });

		forceGenerators.push_back(aGen);

		Particle* pMuelle = new Particle({ x,ini - offset * 2,z }, { 0,0,0 }, { 0,0,0 }, 1, -1, { 0,1,1,1 }, 4, HORSE, 20);
		particles.push_back(pMuelle);

		//springGen_= new SpringForceGenerator(1,5,pFija);
		GravityForceGenerator* gGen = new GravityForceGenerator({ 0.0, -9.8, 0.0 });
		forceGenerators.push_back(gGen);

		//windForceGen = new WindForceGenerator(-1, 0, Vector3(-10, 0, -10), { 7,50,7 }, 20);

		pFR.get()->addRegistry(aGen, pMuelle);
		pFR.get()->addRegistry(gGen, pMuelle);
	}



}
