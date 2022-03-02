#include "minirt.h"

double	plane_intersection(t_vector origin, t_vector ray, t_obj *plane)
{
	double		res;
	t_vector	vec;

	vec = substract_vector(plane->point, origin);
	res = vec_scolar(vec, plane->orient) / vec_scolar(ray, plane->orient);
	return (res);
}
