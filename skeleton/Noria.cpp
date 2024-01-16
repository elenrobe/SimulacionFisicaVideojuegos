#include "Noria.h"

Noria::Noria(physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{

    physx::PxShape* shape2 = CreateShape(physx::PxSphereGeometry(4.0f));

    RBParticle* central = new RBParticle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,0,255,1 }, 5, gPhysics, gScene, shape2, true, 10);
    const int numCabins = 6;
    const float cabinRadius = 50;

    // Create cabins and attach them to the hub
    for (int i = 0; i < numCabins; ++i) {
        float angle = i * 2.0f * PxPi / numCabins;
        float x = cabinRadius * std::cos(angle);

        //float y = 0;
        //float z = cabinRadius * std::sin(angle);
        float y = cabinRadius * std::sin(angle);
        float z = 0.0f;

        physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(4, 4, 4));

        RBParticle* cabina = new RBParticle({ x,y,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,255,0,1 }, 5, gPhysics, gScene, shape, false, 1);
        cabina->getDynamicRigid()->setActorFlag(physx::PxActorFlag::eDISABLE_GRAVITY, true);
        PxVec3 torque(0.0f, 20.0f, 0.0f);
        cabina->getDynamicRigid()->addTorque(torque);
        PxRevoluteJoint* joint = PxRevoluteJointCreate(*gPhysics, central->getStaticRigid(), central->getPos(), cabina->getDynamicRigid(), cabina->getPos());
        joint->setDriveVelocity(1.0f);  // Set rotation speed
        joint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);

        

    }

}
