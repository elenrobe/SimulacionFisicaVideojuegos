# SimulacionFisicaVideojuegos Práctica 5

Al momento de edición de este readme no me van bien las fuerzas con los rigidbody

En clase SceneManager se crean los sistemas de partículas.

Todos los archivos creados para la práctica 5 tienen RB en el nombre, siendo:

#### RBParticle
Similar a la clase Particle, dependiendo de un parámetro en su constructora, se creará con PxRigidStatic o PxRigidDynamic. 

#### RBParticleSystem

#### RBParticleForceRegistry


Aparte de eso he modificado la clase ForceGenerator y todas las que heredan de ella para que puedan actualizar sus fuerzas habiendo un rigidbody, véase el método updateForceRB().
