#include "Noria.h"

Noria::Noria(Vector3 pos, physx::PxPhysics* gPhysics, physx::PxScene* gScene)
{
    float scale = 2;
    physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(1, 40, 15));
    RBParticle* base = new RBParticle({ pos.x-15,pos.y-30,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,1,0,1 }, 5, gPhysics, gScene, shape, true, 100);
    particles.push_back(base);

    physx::PxShape* shape2 = CreateShape(physx::PxSphereGeometry(8.0f));

    RBParticle* central = new RBParticle({ pos.x,pos.y,pos.z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 0,0,0,1 }, 5, gPhysics, gScene, shape2, true, 10);
    const int numCabins = 8;
    const float cabinRadius = 50;
    particles.push_back(central);


    for (int i = 0; i < 12; ++i) {
        float angle = i * 2.0f * PxPi / 12;
        float x = pos.x + 0;

        //float y = 0;
        //float z = cabinRadius * std::sin(angle);
        float y = pos.y + cabinRadius/3*2 * std::sin(angle);
        float z = pos.z + cabinRadius/3*2 * std::cos(angle);

        physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(1, 1, 1));

        RBParticle* cabina = new RBParticle({ x,y,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,0,0,1 }, 5, gPhysics, gScene, shape, true, 1);
        particles.push_back(cabina);
    }

    // Create cabins and attach them to the hub
    for (int i = 0; i < numCabins; ++i) {
        float angle = i * 2.0f * PxPi / numCabins;
        float x = pos.x + 0;

        //float y = 0;
        //float z = cabinRadius * std::sin(angle);
        float y = pos.y + cabinRadius * std::sin(angle);
        float z = pos.z + cabinRadius * std::cos(angle);

        physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(6, 6, 6));

        RBParticle* cabina = new RBParticle({ x,y,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 1,0,0,1 }, 5, gPhysics, gScene, shape, false, 1);
        particles.push_back(cabina);

      
        PxRevoluteJoint* joint = PxRevoluteJointCreate(*gPhysics, central->getStaticRigid(), central->getPos(), cabina->getDynamicRigid(), cabina->getPos());
        joint->setDriveVelocity(0.4f);  // Set rotation speed
        joint->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);

        //physx::PxShape* shape3 = CreateShape(physx::PxBoxGeometry(2, 5, 2));

        //x = 0;

        //y = cabinRadius/2 * std::sin(angle);
        //z = cabinRadius/2 * std::cos(angle);
        //RBParticle* s = new RBParticle({ x,y,z }, { 0,0,0 }, { 0,0,0 }, 0.998, -1, { 255,0,0,1 }, 5, gPhysics, gScene, shape3, false, 1);

        //PxRevoluteJoint* joint2 = PxRevoluteJointCreate(*gPhysics, central->getStaticRigid(), central->getPos(), s->getDynamicRigid(), s->getPos());
        //joint2->setDriveVelocity(0.3f);  // Set rotation speed
        //joint2->setRevoluteJointFlag(PxRevoluteJointFlag::eDRIVE_ENABLED, true);

        

    }

}
