#include "minirt.h"

void	error_exit2(char *str, t_rt *scene)
{
	printf("\033[31m" "ERROR: %s\nCODE: %d", str, -1);
	if (scene->split)
		split_clear(scene->split);
	if (scene->line)
		ft_strdel(&scene->line);
	clean_cam(scene);
	if (scene->mlx)
		free(scene->mlx);
	ft_lstclear(&scene->obj_list, free);
	ft_lstclear(&scene->light_list, free);
	ft_lstclear(&scene->cam_list, free);
	exit(1);
}
