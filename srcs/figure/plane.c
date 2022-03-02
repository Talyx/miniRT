#include "minirt.h"

t_obj	*new_plane(t_vector point, t_vector orient, t_color color)
{
	t_obj	*plane;

	plane = (t_obj *)malloc(sizeof(t_obj));
	plane->id = PLANE;
	plane->point = point;
	plane->orient = orient;
	plane->color = color;
	return (plane);
}
