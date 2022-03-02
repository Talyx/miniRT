#include "minirt.h"

void	parse_sphere(t_rt *scene)
{
	t_obj	*sphere;
	int		check;

	check = count_split(scene->split);
	sphere = (t_obj *)malloc(sizeof(t_obj));
	if (!sphere)
		error_exit2("Ne videlilos pamiat pod sphera", scene);
	if (check != 4)
	{
		free(sphere);
		error_exit2("Ne pravilno zadano count of sphere element", scene);
	}
	sphere->id = SPHERE;
	sphere->point = str_to_vec(scene->split[1], scene);
	sphere->diametr = ft_atof(scene->split[2]);
	sphere->color = split_rgb(scene->split[3], scene);
	ft_lstadd_back(&scene->obj_list, ft_lstnew(sphere));
	if (sphere->diametr < 0)
		error_exit2("Diametr spheri < 0", scene);
}

void	parse_plane(t_rt *scene)
{
	t_obj	*plane;
	int		i;

	i = count_split(scene->split);
	plane = (t_obj *)malloc(sizeof(t_obj));
	if (!plane)
		error_exit2("Memori ne videlilos pod plane", scene);
	if (i != 4 || !get_length_dir(scene->split[2]))
	{
		free(plane);
		error_exit2("Plane dont parse", scene);
	}
	plane->id = PLANE;
	plane->point = str_to_vec(scene->split[1], scene);
	plane->orient = str_to_vec(scene->split[2], scene);
	plane->color = split_rgb(scene->split[3], scene);
	ft_lstadd_back(&scene->obj_list, ft_lstnew(plane));
	if (!check_dirction(plane->orient))
		error_exit2("wrong plane normal", scene);
}

void	parse_square(t_rt *scene)
{
	t_obj	*square;
	int		i;

	i = count_split(scene->split);
	square = (t_obj *)malloc(sizeof(t_obj));
	if (!square)
		error_exit2("Memori ne videlilos pod square", scene);
	if (i != 5 || !get_length_dir(scene->split[2]))
	{
		free(square);
		error_exit2("Square dont parse", scene);
	}
	square->id = SQUARE;
	square->point = str_to_vec(scene->split[1], scene);
	square->orient = str_to_vec(scene->split[2], scene);
	square->height = ft_atof(scene->split[3]);
	square->color = split_rgb(scene->split[4], scene);
	ft_lstadd_back(&scene->obj_list, ft_lstnew(square));
	if (!check_dirction(square->orient))
		error_exit2("wrong square normal", scene);
}

void	parse_triangle(t_rt *scene)
{
	t_obj	*triangle;
	int		i;

	i = count_split(scene->split);
	triangle = (t_obj *)malloc(sizeof(t_obj));
	if (!triangle)
		error_exit2("Memori ne videlilos pod triangle", scene);
	if (i != 5)
	{
		free(triangle);
		error_exit2("Triangle dont parse", scene);
	}
	triangle->id = TRIANGLE;
	triangle->point = str_to_vec(scene->split[1], scene);
	triangle->point2 = str_to_vec(scene->split[2], scene);
	triangle->point3 = str_to_vec(scene->split[3], scene);
	triangle->color = split_rgb(scene->split[4], scene);
	triangle->orient = vec_normolize(vec_cross(
				substract_vector(triangle->point2, triangle->point),
				substract_vector(triangle->point3, triangle->point)));
	ft_lstadd_back(&scene->obj_list, ft_lstnew(triangle));
}

void	parse_cylindre(t_rt *scene)
{
	t_obj	*cylindre;
	int		i;

	i = count_split(scene->split);
	cylindre = (t_obj *)malloc(sizeof(t_obj));
	if (!cylindre)
		error_exit2("Memori ne videlilos pod CYLINDRE", scene);
	if (i != 6 || !get_length_dir(scene->split[2]))
	{
		free(cylindre);
		error_exit2("CYLINDRE dont parse", scene);
	}
	cylindre->id = CYLINDRE;
	cylindre->point = str_to_vec(scene->split[1], scene);
	cylindre->orient = str_to_vec(scene->split[2], scene);
	cylindre->diametr = ft_atof(scene->split[3]);
	cylindre->height = ft_atof(scene->split[4]);
	cylindre->color = split_rgb(scene->split[5], scene);
	ft_lstadd_back(&scene->obj_list, ft_lstnew(cylindre));
	if (!check_dirction(cylindre->orient))
		error_exit2("wrong cylinder normal", scene);
}
