#include "minirt.h"

int	obj_count(t_list *obj)
{
	int		i;
	t_list	*list;

	list = obj;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	bitmap_fileheader(t_rt *scene, int p_size, int fd)
{
	unsigned char	*file_header;
	int				file_size;

	file_header = ft_calloc(14, sizeof(unsigned char));
	if (!file_header)
		error_exit2("maloc fail", scene);
	file_size = 14 + 40 + (scene->cam->img.bpp / 8 * scene->res.x + p_size)
		* scene->res.y;
	*file_header = (unsigned char)('B');
	*(file_header + 1) = (unsigned char)('M');
	*(file_header + 2) = (unsigned char)(file_size);
	*(file_header + 3) = (unsigned char)(file_size >> 8);
	*(file_header + 4) = (unsigned char)(file_size >> 16);
	*(file_header + 5) = (unsigned char)(file_size >> 24);
	*(file_header + 10) = (unsigned char)(54);
	write(fd, file_header, 14);
	free(file_header);
}

void	bitmap_infoheader(t_rt *scene, int fd)
{
	unsigned char	*header;

	header = ft_calloc(40, sizeof(unsigned char));
	if (!header)
		error_exit2("maloc fail", scene);
	*(header) = (unsigned char) 40;
	*(header + 4) = (unsigned char)(scene->res.x);
	*(header + 5) = (unsigned char)(scene->res.x >> 8);
	*(header + 6) = (unsigned char)(scene->res.x >> 16);
	*(header + 7) = (unsigned char)(scene->res.x >> 24);
	*(header + 8) = (unsigned char)(scene->res.y);
	*(header + 9) = (unsigned char)(scene->res.y >> 8);
	*(header + 10) = (unsigned char)(scene->res.y >> 16);
	*(header + 11) = (unsigned char)(scene->res.y >> 24);
	*(header + 12) = (unsigned char)(1);
	*(header + 14) = (unsigned char)(scene->cam->img.bpp);
	write(fd, header, 40);
	free(header);
}

void	create_bmp(t_rt *scene)
{
	int				fd;
	int				p_size;
	int				i;
	unsigned char	p[3];

	i = scene->res.y;
	ft_bzero(p, 3);
	fd = open("test.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!fd)
		error_exit2("fail create bmp file", scene);
	p_size = (4 - (scene->res.x * scene->cam->img.bpp / 8) % 4) % 4;
	bitmap_fileheader(scene, p_size, fd);
	bitmap_infoheader(scene, fd);
	while (i >= 0)
	{
		write(fd, scene->cam->img.add + (i * scene->res.x
				* scene->cam->img.bpp / 8),
			scene->cam->img.size_line);
		write(fd, p, p_size);
		i--;
	}
	close(fd);
}
