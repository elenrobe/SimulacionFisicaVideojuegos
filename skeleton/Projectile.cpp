#include "Projectile.h"

Projectile::Projectile(TYPE currentShotType) : Particle(GetCamera()->getEye(), GetCamera()->getDir(), GetCamera()->getDir())
{
	
	Vector3 const dir = GetCamera()->getDir();
	switch (currentShotType)
	{
	case PISTOL:
		setMass(2.0f); // 2.0 Kg
		setVel(dir*35); // 35 m/s
		setAcc(Vector3(0, -1.0f, 0));
		setDamping(0.99f);
		setColor({ 255, 255, 255, 1 });
		break;
	case ARTILLERY:
		setMass(200.0f); // 200.0 Kg
		setVel(dir*30);
		setAcc(Vector3(0.0f, -20.0f, 0.0f));
		setDamping(0.99f);
		setColor({ 0, 0, 0, 1 });

		break;
	case FIREBALL:
		setMass(1.0f); // 1.0 Kg
		setVel(dir*10);
		setAcc(Vector3(0.0f, 0.6f, 0.0f)); // floats
		setDamping(0.9f);
		setColor({ 255, 0, 0, 1 });
		break;
	case LASER:
		setMass(0.1f); // almost no weight
		setVel(dir*100); // No gravity
		setAcc(Vector3(0.0f, 0.0f, 0.0f));
		setDamping(0.99f);
		setColor({ 0, 255, 255, 1 });
		break;
	case BASE:
		setMass(0.5f); // almost no weight
		setVel(GetCamera()->getDir()*9); 
		setAcc(Vector3(0.0f, -20.0f, 0.0f));
		setDamping(0.998f);
		setColor({ 0, 255, 0, 1 });
		break;
	}
}

Projectile::Projectile(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping, float Mass, Vector4 Color) : Particle(Pos, Vel, Acc, Color)
{

}
