#include "Particle.h"

using namespace std;

class ParticleGenerator
{
public:

	ParticleGenerator();
	virtual ~ParticleGenerator() ;

	void setParticle(Particle* model);
	virtual std::vector<Particle*> generateParticles();

	string getName() { return _name; };
protected:
	string _name;
	Vector3 _mean_pos, _mean_vel;
	double _generation_probability;
	int _num_particles = 5;
	Particle* _model;
};