#include "minirt.h"

double	triangle_intersection(t_vector origin, t_vector ray, t_obj *triangle)
{
	t_triangl	triang;

	triang.e1 = substract_vector(triangle->point2, triangle->point);
	triang.e2 = substract_vector(triangle->point3, triangle->point);
	triang.p_vec = vec_cross(ray, triang.e2);
	triang.det = vec_scolar(triang.e1, triang.p_vec);
	triang.inv_det = 1 / triang.det;
	triang.t_vec = substract_vector(origin, triangle->point);
	triang.u = vec_scolar(triang.t_vec, triang.p_vec) * triang.inv_det;
	triang.q_vec = vec_cross(triang.t_vec, triang.e1);
	triang.v = vec_scolar(ray, triang.q_vec) * triang.inv_det;
	if (triang.u < 0 || triang.u > 1 || triang.v < 0 || triang.u + triang.v > 1)
		return (0);
	triang.result = (vec_scolar(triang.e2, triang.q_vec) * triang.inv_det);
	if (triang.result > EPSILON)
		return (triang.result);
	return (0);
}
