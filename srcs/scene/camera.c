#include "minirt.h"

void	create_cams(t_rt *rt)
{
	t_list	*tmp;

	tmp = rt->cam_list;
	while (tmp)
	{
		rt->cam = tmp->content;
		cam_norm(rt->cam);
		rt->cam->img.ptr = mlx_new_image(rt->mlx, rt->res.x, rt->res.y);
		rt->cam->img.add = mlx_get_data_addr(rt->cam->img.ptr,
				&rt->cam->img.bpp, &rt->cam->img.size_line,
				&rt->cam->img.endian);
		ray_traycing(rt);
		tmp = tmp->next;
	}
}

void	cam_norm(t_camera *cam)
{
	t_vector	up;

	up = new_vector(0, 1, 0);
	cam->revers = vec_normolize(vec_mul(cam->direction, -1));
	cam->right = vec_cross(up, cam->revers);
	if (vec_length(cam->right) == 0)
	{
		up = new_vector(0, 0, -1);
		cam->right = vec_cross(up, cam->revers);
	}
	cam->right = vec_normolize(cam->right);
	cam->up = vec_cross(cam->revers, cam->right);
}

t_camera	*new_camera(t_vector origin, t_vector direction, double fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->origin = origin;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}

void	get_cur_cam(t_rt *rt)
{
	t_list	*cams;
	int		i;

	i = 0;
	cams = rt->cam_list;
	while (cams)
	{
		if (rt->cam_index == i)
		{
			rt->cam = cams->content;
			rt->cam_index++;
			if (rt->cam_index == rt->camera_count)
				rt->cam_index = 0;
			return ;
		}
		i++;
		cams = cams->next;
	}
}

int	check_dirction(t_vector vec)
{
	if (vec.x > 1 || vec.x < -1)
		return (0);
	else if (vec.y > 1 || vec.y < -1)
		return (0);
	else if (vec.z > 1 || vec.z < -1)
		return (0);
	else if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (0);
	return (1);
}
