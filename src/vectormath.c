#include "vector.h"

t_vec vadd(t_vec f, t_vec s)
{
	t_vec vec;

	vec.x = f.x + s.x;
	vec.y = f.y + s.y;
	return (vec);
}

t_vec vsub(t_vec f, t_vec s)
{
	t_vec vec;

	vec.x = f.x - s.x;
	vec.y = f.y - s.y;
	return (vec);
}

t_vec vinv(t_vec f)
{
	t_vec vec;

	vec.x = f.x;
	vec.y = f.y;
	return (vec);
}

t_vec vmulv(t_vec f, t_vec s)
{
	t_vec vec;

	vec.x = f.x * s.x;
	vec.y = f.y * s.y;
	return (vec);
	
}

t_vec vmuls(t_vec f, float s)
{
	t_vec vec;

	vec.x = f.x * s;
	vec.y = f.y * s;
	return (vec);
}

