#include "minirt.h"

t_vector	get_vec_normal(t_rt *rt, t_vector p)
{
	t_vector	normal;

	normal = new_vector(0, 0, 0);
	if (rt->obj->id == SPHERE)
		normal = vec_normolize(substract_vector(p, rt->obj->point));
	return (normal);
}
