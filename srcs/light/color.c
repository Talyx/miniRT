#include "minirt.h"

t_color	color_add(t_color col1, t_color col2)
{
	t_color	color;

	color.r = col1.r + col2.r;
	color.g = col1.g + col2.g;
	color.b = col1.b + col2.b;
	return (color);
}

t_color	new_color(double r, double g, double b)
{
	t_color	color;

	color.r = r / 255;
	color.g = g / 255;
	color.b = b / 255;
	return (color);
}

t_color	color_del(double k, t_color vec)
{
	vec.r /= k;
	vec.g /= k;
	vec.b /= k;
	return (vec);
}

t_color	color_mul(t_color col1, t_color col2)
{
	t_color	color;

	color.r = col1.r * col2.r;
	color.g = col1.g * col2.g;
	color.b = col1.b * col2.b;
	return (color);
}

t_color	color_mul_nbr(double ratio, t_color color)
{
	if (ratio < 1)
	{
		color.r *= ratio;
		color.g *= ratio;
		color.b *= ratio;
	}
	return (color);
}
