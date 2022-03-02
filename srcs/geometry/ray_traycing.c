#include "minirt.h"

t_vector	get_ray(t_rt *scene, double ray_x, double ray_y)
{
	t_vector	ray;
	t_vector	tmp;
	double		x;
	double		y;
	double		z;

	tmp = vec_normolize(new_vector(ray_x, ray_y, -1));
	x = (tmp.x * scene->cam->right.x) + (tmp.y * scene->cam->up.x)
		+ (tmp.z * scene->cam->revers.x);
	y = (tmp.x * scene->cam->right.y) + (tmp.y * scene->cam->up.y)
		+ (tmp.z * scene->cam->revers.y);
	z = (tmp.x * scene->cam->right.z) + (tmp.y * scene->cam->up.z)
		+ (tmp.z * scene->cam->revers.z);
	ray = vec_normolize (new_vector(x, y, z));
	return (ray);
}

int	get_color(t_rt *scene, t_vector ray)
{
	double	closest_t;
	double	len;
	t_list	*tmp;
	t_obj	*obj;

	closest_t = INFINITY;
	tmp = scene->obj_list;
	scene->obj = NULL;
	while (tmp)
	{
		obj = tmp->content;
		len = figure_intersect(scene->cam->origin, ray, obj);
		if (len > 0 && len < closest_t)
		{
			closest_t = len;
			scene->obj = obj;
		}
		tmp = tmp->next;
	}
	if (!scene->obj)
		return (0);
	scene->obj->closes_t = closest_t;
	return (rgb_to_int(calculate_elem(scene, ray)));
}

void	ray_traycing(t_rt *scene)
{
	t_ray		r;
	t_vector	ray;
	t_vplane	*vplane;

	r.mlx_y = 0;
	vplane = get_view_plane(scene, scene->res.x, scene->res.y, scene->cam->fov);
	r.y_angle = (scene->res.y / 2);
	while (r.y_angle >= (scene->res.y / 2 * (-1)))
	{
		r.y_ray = r.y_angle * vplane->y_pixel;
		r.x_angle = (scene->res.x / 2) * (-1);
		r.mlx_x = 0;
		while (r.x_angle <= scene->res.x / 2)
		{
			ray = get_ray(scene, (r.x_angle * vplane->x_pixel), r.y_ray);
			r.color = get_color(scene, ray);
			my_pixel_put(scene, r.mlx_x, r.mlx_y, r.color);
			r.x_angle++;
			r.mlx_x++;
		}
		r.y_angle--;
		r.mlx_y++;
	}
	free(vplane);
}

t_vplane	*get_view_plane(t_rt *scene, double width, double hight, double fov)
{
	t_vplane	*vplane;
	double		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit2("Mistakes pri sozdanii vplane", scene);
	aspect_ratio = width / hight;
	vplane->width = 2 * tan(fov / 2 * (M_PI / 180));
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->hight / hight;
	return (vplane);
}
