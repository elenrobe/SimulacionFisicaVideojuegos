#include "CircleForceGenerator.h"

CircleForceGenerator::CircleForceGenerator(Vector3 speed, Vector3 origin, float r) {


};
void CircleForceGenerator::updateForce(Particle* particle, double t)
{
	if (fabs(particle->getInverseMass()) < 1e-10)
		return;

	//for (int i = 0; i < numAspas; ++i) {
	//	SceneNode* aspa = aspasNode->createChildSceneNode();
	//	Aspa* aspaNode = new Aspa(aspa, mostrarAdorno);
	//	arrayAspas[i] = aspaNode;

	//	//Se le da posicion conforme al numero de aspas que haya en el array
	//	arrayAspas[i]->setPositionAspa(Ogre::Math::Cos(Degree(360 / numAspas * i)) * 100,
	//		Ogre::Math::Sin(Degree(360 / numAspas * i)) * 100, 0);

	//	//Se rota conforme al numero de aspas que haya en el array
	//	arrayAspas[i]->rollAspa(Ogre::Degree(360 / numAspas) * i);
	//}

	//float x = origin_.x + radius * std::cos(angle);
	//float y = origin_.y + radius * std::sin(angle);

	auto x = particle->getPos().p.z + radius * std::cos(angle);
	auto y = particle->getPos().p.y + radius * std::sin(angle);
	auto z = particle->getPos().p.z;

	//particle->setPos(Vector3(x, y, z));
	////windVel_ = K_ * Vector3(x, y, z);
	//Vector3 force = Vector3(x, y, z);

	//particle->addForce(force * particle->getMass());
	angle++;
}

void CircleForceGenerator::updateForceRB(physx::PxRigidDynamic* particle, double t)
{

	if (fabs(particle->getInvMass()) < 1e-10)
		return;



}
