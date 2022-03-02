#include "minirt.h"

t_discr	sphere_intersection(t_vector origin, t_vector ray, t_obj *obj)
{
	double		b;
	double		c;
	double		discr;
	t_discr		di;
	t_vector	cam_sphere;

	di.t1 = 0;
	di.t2 = 0;
	cam_sphere = substract_vector(origin, obj->point);
	b = 2 * (vec_scolar(cam_sphere, ray));
	c = vec_scolar(cam_sphere, cam_sphere) - ((obj->diametr / 2.0)
			* (obj->diametr / 2.0));
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (di);
	di.t1 = ((b * (-1)) - sqrt(discr)) / 2;
	di.t2 = ((b * (-1)) + sqrt(discr)) / 2;
	return (di);
}
