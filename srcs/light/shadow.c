#include "minirt.h"

double	shad_spher(t_discr sqr)
{
	if (sqr.t1 * sqr.t2 > 0.0)
		if (sqr.t1 > sqr.t2)
			return (sqr.t2);
	else
		return (sqr.t1);
	else
		if (sqr.t1 > 0.0)
			return (sqr.t1);
	else
		return (sqr.t2);
}

int	in_shadow(t_rt *rt, t_obj *light, t_vector ray)
{
	t_list		*tmp;
	double		intersect;
	double		vec_len;
	t_vector	p;
	t_vector	p_to_l;

	intersect = 0;
	p = vec_add(rt->cam->origin, vec_mul(ray,
				rt->obj->closes_t * (1 - EPSILON * 1)));
	p_to_l = substract_vector(light->point, p);
	vec_len = vec_length(p_to_l);
	p_to_l = vec_normolize(p_to_l);
	tmp = rt->obj_list;
	while (tmp)
	{
		intersect = shadow_inter(p, p_to_l, tmp->content, vec_len);
		if (intersect < vec_len && intersect > 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

double	shadow_inter(t_vector p, t_vector p_to_l, t_obj *figure, double vec_len)
{
	double	len;

	len = 0;
	if (figure->id == SPHERE)
		len = shad_spher(sphere_intersection(p, p_to_l, figure));
	else if (figure->id == TRIANGLE)
		len = triangle_intersection(p, p_to_l, figure);
	else if (figure->id == PLANE)
		len = plane_intersection(p, p_to_l, figure);
	else if (figure->id == SQUARE)
		len = square_intersection(p, p_to_l, figure);
	else if (figure->id == CYLINDRE)
		len = shad_spher(cylinder_intersection(p, p_to_l, figure, 0));
	return (len);
	(void)vec_len;
}
