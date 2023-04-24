#include "vector.h"
#include "vectormath.h"
#include <math.h>

t_vecd vsqrmag(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y)
}

t_vecd vmag(t_vec vec)
{
	return sqrt(vsqrmag(vec));
}

t_vec vnorm(t_vec vec)
{
	t_vecd mag;

	mag = vmag(vec);
	vec.x /= mag;
	vec.y /= mag;
	return (vec);
}
