#include "minirt.h"

t_obj	*get_trangl(t_vector p1, t_vector p2, t_vector p3)
{
	t_obj	*triangle;

	triangle = malloc(sizeof(t_obj));
	triangle->id = TRIANGLE;
	triangle->point = p1;
	triangle->point2 = p2;
	triangle->point3 = p3;
	triangle->orient = vec_normolize(vec_cross(
				substract_vector(p2, p1),
				substract_vector(p3, p1)));
	return (triangle);
}

t_point	get_point_square(t_obj *square)
{
	t_triangl	tr;
	t_point		points;

	tr.e1 = new_vector(0, 1, 0);
	tr.e2 = vec_cross(square->orient, tr.e1);
	if (vec_length(tr.e2) < EPSILON)
	{
		tr.e1 = new_vector(1, 0, 0);
		tr.e2 = vec_cross(square->orient, tr.e1);
	}
	tr.e2 = vec_normolize(tr.e2);
	tr.p_vec = vec_normolize(vec_cross(square->orient, tr.e2));
	tr.e2 = vec_mul(tr.e2, square->height / 2);
	tr.p_vec = vec_mul(tr.p_vec, square->height / 2);
	tr.q_vec = vec_add(tr.e2, tr.p_vec);
	tr.t_vec = substract_vector(tr.e2, tr.p_vec);
	points.p1 = vec_add(tr.q_vec, square->point);
	points.p2 = vec_add(tr.t_vec, square->point);
	points.p3 = substract_vector(square->point, tr.q_vec);
	points.p4 = substract_vector(square->point, tr.t_vec);
	return (points);
}

double	square_intersection(t_vector origin, t_vector ray, t_obj *square)
{
	t_point	points;
	t_obj	*triang1;
	t_obj	*triang2;
	t_discr	di;

	points = get_point_square(square);
	triang1 = get_trangl(points.p1, points.p2, points.p3);
	triang2 = get_trangl(points.p1, points.p3, points.p4);
	di.t1 = triangle_intersection(origin, ray, triang1);
	di.t2 = triangle_intersection(origin, ray, triang2);
	free(triang1);
	free(triang2);
	if (di.t1 > 0)
		return (di.t1);
	else
		return (di.t2);
}
