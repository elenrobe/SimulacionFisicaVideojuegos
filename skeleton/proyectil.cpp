#include "proyectil.h"

Projectile::Projectile(TYPE currentShotType) : Particle(GetCamera()->getEye(), GetCamera()->getDir(), GetCamera()->getDir())
{
	switch (currentShotType)
	{
	case PISTOL:
		setMass(2.0f); // 2.0 Kg
		setVel(Vector3(0.0f, 0.0f, 35.0f)); // 35 m/s
		setAcc(Vector3(0.0f, -1.0f, 0.0f));
		setDamping(0.99f);
		break;
	case ARTILLERY:
		setMass(200.0f); // 200.0 Kg
		setVel(Vector3(0.0f, 30.0f, 40.0f));
		setAcc(Vector3(0.0f, -20.0f, 0.0f));
		setDamping(0.99f);
		break;
	case FIREBALL:
		setMass(1.0f); // 1.0 Kg
		setVel(Vector3(0.0f, 0.0f, 10.0f));
		setAcc(Vector3(0.0f, 0.6f, 0.0f)); // floats
		setDamping(0.9f);
		break;
	case LASER:
		setMass(0.1f); // almost no weight
		setVel(Vector3(0.0f, 0.0f, 100.0f)); // No gravity
		setAcc(Vector3(0.0f, 0.0f, 0.0f));
		setDamping(0.99f);
		break;
	case BASE:
		setMass(0.5f); // almost no weight
		setVel(GetCamera()->getDir()); // No gravity
		setAcc(Vector3(0.0f, -0.1f, -1.0f));
		setDamping(0.998f);
		setColor({ 0, 255, 255, 1 });
		break;
	}
}

Projectile::Projectile(Vector3 Pos, Vector3 Vel, Vector3 Acc, float Damping, float Mass, Vector4 Color) : Particle(Pos, Vel, Acc, Color)
{

}
