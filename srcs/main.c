#include "minirt.h"

void	my_pixel_put(t_rt *scene, int x, int y, int color)
{
	char	*dst;

	dst = scene->cam->img.add + (y * scene->cam->img.size_line
			+ x * (scene->cam->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	check_filename(char *str)
{
	char	**split;
	int		len;

	split = ft_split(str, '.');
	len = count_split(split);
	if (len > 0 && ft_strequ("rt", split[len -1]))
	{
		split_clear(split);
		return (1);
	}
	return (0);
}

void	start(t_rt *scene)
{
	scene->mlx = mlx_init();
	if (!scene->save)
		scene->window = mlx_new_window (scene->mlx, scene->res.x,
				scene->res.y, "miniRT");
	create_cams(scene);
	get_cur_cam(scene);
	if (scene->save)
	{
		printf("BMP file start create\n");
		create_bmp(scene);
		clean(scene);
	}	
	mlx_hook(scene->window, 2, 1L << 0, change_cam, scene);
	mlx_hook(scene->window, 33, 3, finish_programm, scene);
	mlx_put_image_to_window(scene->mlx, scene->window,
		scene->cam->img.ptr, 0, 0);
	mlx_loop(scene->mlx);
}

int	main(int argc, char **argv)
{
	t_rt	scene;

	ft_bzero(&scene, sizeof(t_rt));
	if (argc > 3 || (argc == 3 && !ft_strequ(argv[2], "--save")) || argc == 1)
		error_exit2("wrong number of main argument", &scene);
	if (ft_strequ(argv[2], "--save"))
		scene.save = 1;
	if (!check_filename(argv[1]))
		error_exit2("wrong file name", &scene);
	parse_rt(argv[1], &scene);
	start(&scene);
	return (0);
}
