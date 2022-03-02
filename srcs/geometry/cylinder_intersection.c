#include "minirt.h"

t_vector	get_cam_cylin(t_vector ori, t_obj *cylinder)
{
	t_vector	result;
	t_vector	mult;
	t_vector	cntr;

	mult = vec_mul(cylinder->orient, cylinder->height /2);
	cntr = vec_add(cylinder->point, mult);
	result = substract_vector(ori, cntr);
	return (result);
}

double	inter_cap(t_vector origin, t_vector ray, t_obj *pl, double diametr)
{
	double		res;
	double		d2;
	t_vector	p;
	t_vector	v;

	res = plane_intersection(origin, ray, pl);
	if (res > 0)
	{
		p = vec_add(vec_mul(ray, res), origin);
		v = substract_vector(p, pl->point);
		d2 = vec_scolar(v, v);
		if (sqrt(d2) <= diametr / 2)
		{
			return (res);
		}
	}
	return (-1);
}

void	set_norm(t_cylind cylin, t_vector origin, t_vector ray, t_obj *cylinder)
{
	if (shad_spher(cylin.res) == shad_spher(cylin.pl))
		cylinder->n = vec_mul(cylinder->orient, 1);
	else if (shad_spher(cylin.res) == shad_spher(cylin.di)
		&& shad_spher(cylin.res) > 0)
	{
		cylin.sur = vec_add(vec_mul(ray, shad_spher(cylin.di)), origin);
		set_tube(cylin.sur, cylinder, cylin.pl1->point, cylin.m);
	}
}

t_discr	cylinder_intersection(t_vector origin, t_vector ray,
								t_obj *cylinder, double set)
{
	t_cylind	cylin;

	cylin.cam_cylin = get_cam_cylin(origin, cylinder);
	cylin.di = get_dsqrt(ray, cylinder, cylin.cam_cylin);
	cylin.m = get_m(cylinder, cylin.di, cylin.cam_cylin, ray);
	if (cylin.m <= 0 && cylin.m >= -cylinder->height)
		cylin.res.t1 = shad_spher(cylin.di);
	else
		cylin.res.t1 = -1;
	cylin.p1 = vec_add(vec_mul(cylinder->orient,
				cylinder->height / 2), cylinder->point);
	cylin.p2 = vec_add(vec_mul(cylinder->orient,
				-cylinder->height / 2), cylinder->point);
	cylin.pl1 = new_plane(cylin.p1, cylinder->orient, cylinder->color);
	cylin.pl2 = new_plane(cylin.p2, cylinder->orient, cylinder->color);
	cylin.pl.t1 = inter_cap(origin, ray, cylin.pl1, cylinder->diametr);
	cylin.pl.t2 = inter_cap(origin, ray, cylin.pl2, cylinder->diametr);
	cylin.res.t2 = get_closes(cylin.pl);
	if (set)
		set_norm(cylin, origin, ray, cylinder);
	free(cylin.pl1);
	free(cylin.pl2);
	return (cylin.res);
}
