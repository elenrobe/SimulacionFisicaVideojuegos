#include "sceneManager.h"

void SceneManager::createAxis()
{

	xAxis = std::make_unique<Particle>(Vector3(30, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(255, 0, 0, 1)); //red
	yAxis = std::make_unique<Particle>(Vector3(0, 30, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(0, 255, 0, 1)); //green
	zAxis = std::make_unique<Particle>(Vector3(0, 0, 40), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector4(0, 0, 255, 1)); ///blue
	centerAxis = std::make_unique<Particle>(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0)); //clanco

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

SceneManager::SceneManager()
{
	cam = GetCamera();
}

SceneManager::~SceneManager()
{
}

void SceneManager::initScene()
{
	createAxis();
	//proyectiles.push_back(new Projectile(Projectile::BASE));

}

void SceneManager::integrate(double t)
{
	for (auto p : proyectiles)
	{
		if (p != nullptr && p->getAlive())
		{
			p->integrate(t);

			if (!p->getAlive()) {/*
				delete p;
				p = nullptr;*/
			}

		}
	}

}

void SceneManager::shoot(char key)
{

	switch (toupper(key))
	{
	case ' ':
	{
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
