#include "minirt.h"

void	print_vector(t_vector vec, char *str)
{
	printf("%s.x = %f, %s.y = %f, %s.z = %f\n",
		str, vec.x, str, vec.y, str, vec.z);
}

t_color	calculate_elem(t_rt *scene, t_vector ray)
{
	t_calc	c;

	c.ambient = color_mul_nbr(scene->ambient.ratio, scene->ambient.color);
	c.p = vec_add(scene->cam->origin, vec_mul(ray, scene->obj->closes_t));
	if (scene->light == 1)
	{
		if (scene->obj->id == SPHERE)
		{
			c.n = get_vec_normal(scene, c.p);
			c.result = color_mul(scene->obj->color, color_add(c.ambient,
						compute_lighting(scene, c.n, ray, c.p)));
		}
		else if (scene->obj->id == PLANE || scene->obj->id == SQUARE
			|| scene->obj->id == TRIANGLE)
			c.result = color_mul(scene->obj->color, color_add(c.ambient,
						compute_lighting(scene, scene->obj->orient, ray, c.p)));
		else if (scene->obj->id == CYLINDRE)
			c.result = color_mul(scene->obj->color, color_add(c.ambient,
						compute_lighting(scene, scene->obj->n, ray, c.p)));
		else
			c.result = color_mul(c.ambient, scene->obj->color);
	}
	else
		c.result = color_mul(c.ambient, scene->obj->color);
	return (c.result);
}

t_color	compute_lighting(t_rt *scene, t_vector n, t_vector ray, t_vector p)
{
	t_list		*tmp;
	t_obj		*light;
	t_color		color;
	t_vector	norm_mod;

	color = new_color(0, 0, 0);
	tmp = scene->light_list;
	while (tmp)
	{
		light = tmp->content;
		if (vec_scolar(ray, n) > 0)
			norm_mod = vec_mul(n, -1);
		else
			norm_mod = new_vector(n.x, n.y, n.z);
		if (!in_shadow(scene, light, ray))
			color = color_add(color, point_light(norm_mod, light, p));
		tmp = tmp->next;
	}
	return (color);
}

t_color	point_light(t_vector n, t_obj *light, t_vector p)
{
	t_vector	L;
	double		lum;
	double		dot;
	t_color		color;

	color = new_color(0, 0, 0);
	L = substract_vector(light->point, p);
	dot = vec_scolar(n, L);
	lum = dot / (vec_length(n) * vec_length(L));
	if (dot > 0)
		color = color_mul_nbr(light->ratio * lum, light->color);
	return (color);
}
