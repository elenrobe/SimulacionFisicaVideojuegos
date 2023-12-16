#pragma once
#pragma once
#include <map>
#include "ForceGenerator.h"

typedef std::pair< ForceGenerator*, physx::PxRigidDynamic*> FRPairRB;

class RBParticleForceRegistry :public std::multimap<ForceGenerator*, physx::PxRigidDynamic*>
{
public:
	void updateForces(double duration) {
		for (auto it = begin(); it != end(); it++) {
			it->first->updateForceRB(it->second, duration);
		}
	}
	void addRegistry(ForceGenerator* fg, physx::PxRigidDynamic* p) {
		insert({ fg, p });

	}
	void deleteParticleRegistry(physx::PxRigidDynamic* p) {
		for (auto it = begin(); it != end(); ) {
			if (it->second == p) {
				it = erase(it);
			}
			else it++;
		}
	}
	void deleteForce() {
		for (auto it = begin(); it != end(); ) {
			it = erase(it);
		}
	}
};

