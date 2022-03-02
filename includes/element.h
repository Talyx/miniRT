#ifndef ELEMENT_H
# define ELEMENT_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct s_res
{
	int	x;
	int	y;
	int	parsed;
}				t_res;

typedef struct s_ambient
{
	double	ratio;
	int		parsed;
	t_color	color;
}				t_ambient;

typedef struct s_image
{
	void	*ptr;
	char	*add;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_discr
{
	double	t1;
	double	t2;
}				t_discr;
#endif