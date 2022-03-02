#include "minirt.h"

double	get_m(t_obj *cylinder, t_discr di, t_vector cam_cylinder, t_vector ray)
{
	double		m;
	t_vector	tmp;

	tmp = vec_mul(cylinder->orient, get_closes(di));
	m = vec_scolar(ray, tmp) + vec_scolar(cam_cylinder, cylinder->orient);
	return (m);
}

t_discr	get_dsqrt(t_vector ray, t_obj *cylinder, t_vector cam_cylinder)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	t_discr	di;

	di.t1 = 0;
	di.t2 = 0;
	a = vec_scolar(ray, ray) - pow(vec_scolar(ray, cylinder->orient), 2);
	b = vec_scolar(ray, cam_cylinder) - vec_scolar(ray, cylinder->orient)
		* vec_scolar(cam_cylinder, cylinder->orient);
	c = vec_scolar(cam_cylinder, cam_cylinder)
		- pow(vec_scolar(cam_cylinder, cylinder->orient), 2)
		- pow((cylinder->diametr / 2), 2);
	b = 2.0 * b;
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (di);
	di.t1 = (-b - sqrt(discr)) / (2 * a);
	di.t2 = (-b + sqrt(discr)) / (2 * a);
	return (di);
}

void	set_tube(t_vector sur, t_obj *cylinder, t_vector pl_pos, double m)
{
	t_vector	p;
	t_vector	norm;

	norm = vec_mul(cylinder->orient, m);
	p = vec_add(pl_pos, norm);
	cylinder->n = vec_normolize(substract_vector(sur, p));
}
