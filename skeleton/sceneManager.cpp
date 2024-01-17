#include "sceneManager.h"

void SceneManager::initScene()
{
	proyectoFinal();
	return;

	if (rigidBodyOn)
		initSceneRB();
	else {
		createAxis();
		createParticleSystem();
	}


}

void SceneManager::initSceneRB()
{

	rb_pSym = new RBParticleSystem(gPhysics, gScene);

	rigidBodyOn = true;

}

void SceneManager::createAxis()
{

	xAxis = new Particle(Vector3(30, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(255, 0, 0, 1)); //red
	yAxis = new Particle(Vector3(0, 30, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(0, 255, 0, 1)); //green
	zAxis = new Particle(Vector3(0, 0, 40), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(0, 0, 255, 1)); ///blue
	centerAxis = new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0)); //clanco

}

void SceneManager::toDelete()
{
	//que recorra los objetos a ver si estan alive y los borre si no
	for (int i = 0; i < proyectiles.size(); i++) {
		//proyectiles[i]->Update(t);
		if (!proyectiles[i]->getAlive()) {
			delete proyectiles[i];
			proyectiles.erase(proyectiles.begin() + i);
		}
	}
}

void SceneManager::createParticleSystem()
{
	pSym = new ParticleSystem();
}

SceneManager::SceneManager()
{
	cam = GetCamera();
}

SceneManager::SceneManager(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
	cam = GetCamera();
	this->gPhysics = gPhysics;
	this->gScene = gScene;

}

SceneManager::~SceneManager()
{
	delete xAxis;
	delete yAxis;
	delete zAxis;
	delete centerAxis;

}


void SceneManager::integrate(double t)
{
	for (auto p : proyectiles)
	{
		if (p != nullptr && p->getAlive())
		{
			p->integrate(t);


		}
	}


		rb_pSym->update(t);
		pSym->update(t);
}

void SceneManager::shoot(char key)
{

	switch (toupper(key))
	{
	case ' ':
	{
		break;
	}
	case 'H':
	{
		if (!rigidBodyOn)
			pSym->changeWind();
		else {
			rb_pSym->addWind();
		}
		break;
	}
	case 'J':
	{
		if (!rigidBodyOn)
			pSym->changeWhirlwind();
		else
			rb_pSym->changeWhirlwind();

		break;
	}
	case 'G':
	{

		if(!rigidBodyOn)
			pSym->changeGravity();
		break;
	}
	case 'K':
	{

		if (rigidBodyOn) {
			rb_pSym->addExplosion();
		}
		else {
			rb_pSym->addExplosion();

			pSym->changeExplosion();
			pSym->addExplosion();
		}
		break;
	}
	case 'O':
	{
		if (rigidBodyOn) {
			rb_pSym->createManguerSystem();
		}
		else {

			pSym->createManguerSystem();
		}	
		break;
	}
	case 'P':
	{
		if (!rigidBodyOn)
			pSym->createNieblaSystem();
		break;
	}
	case 'L':
	{
		if(!rigidBodyOn)
			pSym->addSomeParticles();
		else {
			rb_pSym->generateParticles();
		}
		break;
	}
	case 'V':
	{
		proyectiles.push_back(new Projectile(Projectile::ARTILLERY));
		break;
	}
	case 'B':
	{
		proyectiles.push_back(new Projectile(Projectile::PISTOL));
		break;
	}
	case 'N':
	{
		proyectiles.push_back(new Projectile(Projectile::FIREBALL));
		break;
	}
	case 'M':
	{
		proyectiles.push_back(new Projectile(Projectile::LASER));
		break;
	}
	case 'R':
	{
		pSym->deleteAll();

		rb_pSym->deleteAll();
		break;
	}
	case 'F':
	{
		pSym->shootFirework(2);

		break;
	}
	case 'C':
	{
		rb_pSym->shootBullet();

		break;
	}
	default:
		//rb_pSym->deleteAll();
		//proyectiles.push_back(new Projectile(Projectile::BASE));
		break;
	}

}


void SceneManager::keyPressed(char key)
{
	shoot(key);
}

void SceneManager::proyectoFinal()
{
	createParticleSystem();

	rb_pSym = new RBParticleSystem(gPhysics, gScene);
}

void SceneManager::checkColisions(physx::PxActor* snowman, physx::PxActor* actor2)
{
	rb_pSym->checkCollisions(snowman, actor2);
}

