#include "minirt.h"

void	parse_rt(char *file_name, t_rt *scene)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit2("File not open\n", scene);
	while (get_next_line(fd, &scene->line))
	{
		scene->split = ft_ssplit(scene->line, " ");
		if (scene->split[0])
			parse_type(scene);
		scene->split = split_clear(scene->split);
		ft_strdel(&scene->line);
	}
	close(fd);
	scene->obj_count = obj_count(scene->obj_list);
	scene->camera_count = obj_count(scene->cam_list);
	if (!scene->camera_count)
		error_exit2("no camera", scene);
}

void	parse_res(t_rt *scene)
{
	scene->res.x = ft_atoi(scene->split[1]);
	scene->res.y = ft_atoi(scene->split[2]);
	scene->res.parsed = 1;
	if (scene->res.x < 1 || scene->res.y < 1)
		error_exit2("the Resolution is not set correctly", scene);
	if (scene->res.x > 1920)
		scene->res.x = 1920;
	if (scene->res.y > 1080)
		scene->res.y = 1080;
}

void	parse_ambient(t_rt *scene)
{
	scene->ambient.ratio = ft_atof(scene->split[1]);
	scene->ambient.color = split_rgb(scene->split[2], scene);
	if (scene->ambient.ratio > 1 || scene->ambient.ratio < 0)
		error_exit2("ambient is incorrect", scene);
	scene->ambient.parsed = 1;
}

void	parse_camera(t_rt *scene)
{
	t_vector	origin;
	t_vector	direction;
	t_camera	*camera;

	if (count_split(scene->split) != 4 || !get_length_dir(scene->split[2]))
		error_exit2("there is an error in the camera line", scene);
	origin = str_to_vec(scene->split[1], scene);
	direction = str_to_vec(scene->split[2], scene);
	if (!check_dirction(direction))
		error_exit2("wrong direction of camera", scene);
	camera = new_camera(origin, direction, ft_atoi(scene->split[3]));
	scene->cam_index = 0;
	ft_lstadd_back(&scene->cam_list, ft_lstnew(camera));
}

void	parse_light(t_rt *scene)
{
	t_obj	*light;

	light = malloc(sizeof(t_obj));
	if (!light)
		error_exit2("malloc fail", scene);
	if (count_split(scene->split) != 4)
	{
		free(light);
		error_exit2("there is an error in the light line", scene);
	}
	light->id = 10;
	light->point = str_to_vec(scene->split[1], scene);
	light->ratio = ft_atof(scene->split[2]);
	light->color = split_rgb(scene->split[3], scene);
	scene->light = 1;
	ft_lstadd_back(&scene->light_list, ft_lstnew(light));
	if (light->ratio > 1 || light->ratio < 0)
		error_exit2("wrong light range", scene);
}
