#include "minirt.h"

t_vector	new_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	substract_vector(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = new_vector(vec1.x - vec2.x,
			vec1.y - vec2.y, vec1.z - vec2.z);
	return (res);
}

t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = new_vector(vec1.x + vec2.x,
			vec1.y + vec2.y, vec1.z + vec2.z);
	return (res);
}

t_vector	vec_mul(t_vector vec1, double k)
{
	vec1.x *= k;
	vec1.y *= k;
	vec1.z *= k;
	return (vec1);
}

double	vec_length(t_vector vec)
{
	double	length;

	length = sqrt((vec.x * vec.x) + (vec.y * vec.y)
			+ (vec.z * vec.z));
	return (length);
}
