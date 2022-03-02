#include "minirt.h"

t_vector	vec_normolize(t_vector vec)
{
	double	length;

	length = vec_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

t_vector	vec_del(double k, t_vector vec)
{
	vec.x /= k;
	vec.y /= k;
	vec.z /= k;
	return (vec);
}

double	vec_scolar(t_vector vec1, t_vector vec2)
{
	double	res;

	res = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (res);
}

t_vector	vec_cross(t_vector vec1, t_vector vec2)
{
	t_vector	vec;

	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec);
}
