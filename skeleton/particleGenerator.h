#include "particle.h"
#include <iostream>

using namespace std;

class ParticleGenerator
{
public:
	ParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles);
	~ParticleGenerator() = default;
	void setParticle(Particle* model);
	virtual vector<Particle*> generateParticles() = 0;

	string getName() { return _name; };
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double _generation_probability;
	int _num_particles = 5;
	Particle* _model = nullptr;
};