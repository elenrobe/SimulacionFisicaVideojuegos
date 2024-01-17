#include "CircleParticleGenerator.h"
//#include "CircleParticleGenerator.h"

CircleParticleGenerator::CircleParticleGenerator(Vector3 meanVel, double gen_prob, double radius, Particle* model, double numPart)
{
    gen_prob_dist = std::uniform_real_distribution<double>(0, 1);
    _mean_vel = meanVel;
    _name = "CircleParticleGenerator";
    radius_ = radius;
    _generation_probability = gen_prob;
    _num_particles = numPart;
    _model = model;

}

vector<Particle*> CircleParticleGenerator::generateParticles()
{
    std::vector<Particle*> vP;

    float angle = 0;
    for (int i = 0; i < _num_particles; i++) {

        int genProbRnd = gen_prob_dist(gen_);

        if (genProbRnd < _generation_probability) {

            Particle* p;

            p = _model->clone();
            angle = 360 / _num_particles * i;

            Vector3 posi(p->getPos().p.x + cos(angle * (std::_Pi / 180)) * radius_, std::sin(angle * (std::_Pi / 180)) * radius_ +p->getPos().p.y, p->getPos().p.z);
            Vector3 velo = Vector3(cos(angle * (std::_Pi / 180)), sin(angle * (std::_Pi / 180)), 0);

            p->setVel({ velo.x * _mean_vel.x,velo.y * _mean_vel.y,velo.z * _mean_vel.z });
            p->setPos(posi);

            vP.push_back(p);
        }
    }
    return vP;
}


