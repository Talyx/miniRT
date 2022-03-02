#include "minirt.h"

double	get_closes(t_discr sqr)
{
	if ((sqr.t1 * sqr.t2) > 0 && sqr.t1 > 0)
	{
		if (sqr.t1 > sqr.t2)
			return (sqr.t2);
		else
			return (sqr.t1);
	}
	else if ((sqr.t1 * sqr.t2) < 0)
	{
		if (sqr.t1 > sqr.t2)
			return (sqr.t1);
		else
			return (sqr.t2);
	}
	else
		return (0);
}

double	figure_intersect(t_vector origin, t_vector ray, t_obj *obj)
{
	double	intersection;

	intersection = 0;
	if (obj->id == SPHERE)
		intersection = get_closes(sphere_intersection(origin, ray, obj));
	else if (obj->id == PLANE)
		intersection = plane_intersection(origin, ray, obj);
	else if (obj->id == SQUARE)
		intersection = square_intersection(origin, ray, obj);
	else if (obj->id == TRIANGLE)
		intersection = triangle_intersection(origin, ray, obj);
	else if (obj->id == CYLINDRE)
	{
		intersection = shad_spher(cylinder_intersection(origin, ray, obj, 1));
	}
	return (intersection);
}
