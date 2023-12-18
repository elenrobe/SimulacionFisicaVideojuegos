# SimulacionFisicaVideojuegos Práctica 5

Lia si estás corrigiendo todavía no he terminado pero lo estoy haciendo ahora mismo

En clase SceneManager se crean los sistemas de partículas.

Todos los archivos creados para la práctica 5 tienen RB en el nombre, siendo:

#### RBParticle
Similar a la clase Particle, dependiendo de un parámetro en su constructora, se creará con PxRigidStatic o PxRigidDynamic. 

#### RBParticleSystem

#### RBParticleForceRegistry

#### RBParticleGenerator

#### RBUniformParticleGenerator

Aparte de eso he modificado la clase ForceGenerator y todas las que heredan de ella para que puedan actualizar sus fuerzas habiendo un rigidbody, véase el método updateForceRB().

### Teclas

* La tecla k es la de la explosión
* La tecla H es de poner viento/wind

