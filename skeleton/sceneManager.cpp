#include "sceneManager.h"

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

SceneManager::~SceneManager()
{
	delete xAxis;
	delete yAxis;
	delete zAxis;
	delete centerAxis;


	/*
	xAxis = nullptr;
	std::unique_ptr<Particle> yAxis;
	std::unique_ptr<Particle> zAxis;
	std::unique_ptr<Particle> centerAxis;*/
}

void SceneManager::initScene()
{
	createAxis();
	createParticleSystem();
	//proyectiles.push_back(new Projectile(Projectile::BASE));

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
		pSym->changeWind();
		break;
	}
	case 'J':
	{
		pSym->changeWhirlwind();
		break;
	}
	case 'G':
	{
		pSym->changeGravity();
		break;
	}
	case 'K':
	{
		pSym->changeExplosion();
		pSym->addExplosion();
		break;
	}
	case 'O':
	{
		pSym->createManguerSystem();
		break;
	}
	case 'P':
	{
		pSym->createNieblaSystem();
		break;
	}
	case 'L':
	{
		pSym->addSomeParticles();
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
	default:
		proyectiles.push_back(new Projectile(Projectile::BASE));
		break;
	}

}


void SceneManager::keyPressed(char key)
{
	shoot(key);
}