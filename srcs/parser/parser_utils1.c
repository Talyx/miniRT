#include "minirt.h"

void	parse_type(t_rt *scene)
{
	if (ft_strequ(scene->split[0], "R") && scene->res.parsed != 1)
		parse_res(scene);
	else if (ft_strequ(scene->split[0], "A") && scene->ambient.parsed != 1)
		parse_ambient(scene);
	else if (ft_strequ(scene->split[0], "c"))
		parse_camera(scene);
	else if (ft_strequ(scene->split[0], "l"))
		parse_light(scene);
	else if (ft_strequ(scene->split[0], "sp"))
		parse_sphere(scene);
	else if (ft_strequ (scene->split[0], "pl"))
		parse_plane(scene);
	else if (ft_strequ(scene->split[0], "sq"))
		parse_square(scene);
	else if (ft_strequ(scene->split[0], "cy"))
		parse_cylindre(scene);
	else if (ft_strequ(scene->split[0], "tr"))
		parse_triangle(scene);
	else if (ft_strequ(scene->split[0], "#"))
		return ;
	else
		error_exit2("map error", scene);
}

t_color	split_rgb(char *rgb, t_rt *scene)
{
	t_color	col;
	char	**split;

	split = ft_split(rgb, ',');
	if (count_split(split) != 3 || ft_str_c_count(rgb, ',') != 2)
	{
		split_clear(split);
		error_exit2("RGB ERROR", scene);
	}
	if (!check_color(split))
		error_exit2("RGB ERROR", scene);
	col.r = ft_atof(split[0]) / 255.0;
	col.g = ft_atof(split[1]) / 255.0;
	col.b = ft_atof(split[2]) / 255.0;
	split_clear(split);
	if (col.r > 1 || col.g > 1 || col.b > 1
		|| col.r < 0 || col.g < 0 || col.b < 0)
		error_exit2("RGB ERROR2", scene);
	return (col);
}

t_vector	str_to_vec(char *str, t_rt *scene)
{
	char		**split;
	t_vector	vector;
	double		x;
	double		y;
	double		z;

	split = ft_split(str, ',');
	if (count_split(split) != 3 || ft_str_c_count(str, ',') != 2)
	{
		split_clear(split);
		error_exit2("invalid vector", scene);
	}
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	vector = new_vector(x, y, z);
	split_clear(split);
	return (vector);
}

int	count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

char	**split_clear(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return (split);
}
