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
		if (p != nullptr)
		{
			p->integrate(t);

			if (!p->getAlive()) {
				delete p;
				p = nullptr;
			}

		}
	}

}

void SceneManager::shoot()
{

	//Vector3 vel = cam->getDir();

	//vel *= 25;
	//Vector3 pos = cam->getEye();
	//Vector3 acc = { 0,-0.1,0 };

	proyectiles.push_back(new Projectile(Projectile::BASE));

}
