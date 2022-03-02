#include "minirt.h"

void	switch_cam(t_rt *scene)
{
	if (scene->camera_count > 1)
	{
		get_cur_cam(scene);
		mlx_put_image_to_window(scene->mlx, scene->window,
			scene->cam->img.ptr, 0, 0);
	}
}

int	finish_programm(int keycode, t_rt *scene)
{
	(void)keycode;
	(void)scene;
	exit(0);
	return (0);
}

int	change_cam(int keycode, t_rt *scene)
{
	if (keycode == 0x20)
		switch_cam(scene);
	else if (keycode == 0xFF1B)
		clean(scene);
	return (1);
}
