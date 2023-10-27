#include "gaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator(string name, Vector3 pos, Vector3 vel, double genProb, int numParticles, Particle* model, Vector3 std_dev_pos, Vector3 std_dev_vel)
{

    _name = name;
    _mean_pos = pos;
    _mean_vel = vel;
    _generation_probability = genProb;
    _num_particles = numParticles; 
    this->std_dev_pos = std_dev_pos;
    this->std_dev_vel = std_dev_vel;
    _model = model;
    std:random_device rd;
    random_generator = std::mt19937(rd());
}

vector<Particle*> GaussianParticleGenerator::generateParticles()
{

    vector<Particle*>vP;
    for (int i = 0; i < _num_particles; i++) {
        std::normal_distribution<double> valor(0, 1); //da entre 0 y 1
        if (valor(random_generator) < _generation_probability) {

            //si se genera ya le ponemos todo 

            auto posX = std::normal_distribution<float>(_mean_pos.x, std_dev_pos.x);
            auto posY = std::normal_distribution<float>(_mean_pos.y,std_dev_pos.y);
            auto posZ = std::normal_distribution<float>(_mean_pos.z, std_dev_pos.z);
            auto velX = std::normal_distribution<float>(_mean_vel.x,std_dev_vel.x);
            auto velY = std::normal_distribution<float>(_mean_vel.y,std_dev_vel.y);
            auto velZ = std::normal_distribution<float>(_mean_vel.z,std_dev_vel.z);

            Vector3 pos = Vector3(posX(random_generator), posY(random_generator), posZ(random_generator));
            Vector3 vel = Vector3(velX(random_generator), velY(random_generator), velZ(random_generator));
            Particle* p = _model->clone();

            p->setVel(vel);
            p->setPos(pos);
            vP.push_back(p);
        }
    }
    return vP;
}
