#ifndef SCENE_H
# define SCENE_H

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	t_image		img;
	t_vector	up;
	t_vector	right;
	t_vector	revers;
	double		fov;
}				t_camera;

t_camera		*new_camera(t_vector origin, t_vector direction, double fov);
#endif