#include "minirt.h"

int	rgb_to_int(t_color col)
{
	int	color;
	int	tmp;

	tmp = col.r * 0xFF;
	if (tmp > 0xFF)
		tmp = 0xFF;
	color = tmp;
	color = color << 8;
	tmp = col.g * 0xFF;
	if (tmp > 0xFF)
		tmp = 0xFF;
	color += tmp;
	color = color << 8;
	tmp = col.b * 0xFF;
	if (tmp > 0xFF)
		tmp = 0xFF;
	color += tmp;
	return (color);
}

int	check_color(char **rgb)
{
	double	r;
	double	g;
	double	b;

	if (rgb[0][0] == '-' || rgb[1][0] == '-' || rgb[2][0] == '-')
		return (0);
	r = ft_atof(rgb[0]);
	g = ft_atof(rgb[1]);
	b = ft_atof(rgb[2]);
	if (r < 0 || r > 255)
		return (0);
	else if (b < 0 || b > 255)
		return (0);
	else if (g < 0 || g > 255)
		return (0);
	return (1);
}
