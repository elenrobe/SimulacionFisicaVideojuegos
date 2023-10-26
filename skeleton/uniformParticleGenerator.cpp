#include "uniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator(string name, Vector3 pos,  Vector3 vel, double genProb, int numParticles, Particle* model, Vector3 posWidth, Vector3 velWidth )
{
    _name = "Uniforme";
    _mean_pos = pos;
    _mean_vel = vel;
    _generation_probability = genProb;
    _num_particles = numParticles;
    _pos_width = posWidth;
    _vel_width = velWidth;
	_model = model;
	std:random_device rd;
	random_generator = std::mt19937(rd());

}

vector<Particle*> UniformParticleGenerator::generateParticles()
{
    vector<Particle*>vP;
    for (int i = 0; i < _num_particles; i++) {
        std::uniform_real_distribution<double> valor(0, 1); //da entre 0 y 1
        if (valor(random_generator) < _generation_probability) {

            //si se genera ya le ponemos todo 

            auto posX = std::uniform_real_distribution<float>(_mean_pos.x - _pos_width.x / 2, _mean_pos.x + _pos_width.x / 2);
            auto posY = std::uniform_real_distribution<float>(_mean_pos.y - _pos_width.y / 2, _mean_pos.y + _pos_width.y / 2);
            auto posZ = std::uniform_real_distribution<float>(_mean_pos.z - _pos_width.z / 2, _mean_pos.z + _pos_width.z / 2);
            auto velX = std::uniform_real_distribution<float>(_mean_vel.x - _vel_width.x / 2, _mean_vel.x + _vel_width.x / 2);
            auto velY = std::uniform_real_distribution<float>(_mean_vel.y - _vel_width.y / 2, _mean_vel.y + _vel_width.y / 2);
            auto velZ = std::uniform_real_distribution<float>(_mean_vel.z - _vel_width.z / 2, _mean_vel.z + _vel_width.z / 2);

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
