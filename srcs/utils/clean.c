#include "minirt.h"

void	clean_cam(t_rt *scene)
{
	t_list		*tmp;
	t_camera	*cam;
	int			i;

	i = 0;
	tmp = scene->cam_list;
	while (tmp)
	{
		cam = tmp->content;
		if (cam->img.ptr)
			mlx_destroy_image(scene->mlx, cam->img.ptr);
		tmp = tmp->next;
		i++;
	}
}

void	clean(t_rt *scene)
{
	clean_cam(scene);
	ft_lstclear(&scene->obj_list, free);
	ft_lstclear(&scene->light_list, free);
	ft_lstclear(&scene->cam_list, free);
	if (!scene->save)
	{
		mlx_clear_window(scene->mlx, scene->window);
		mlx_destroy_window(scene->mlx, scene->window);
	}
	free(scene->mlx);
	exit(0);
}
