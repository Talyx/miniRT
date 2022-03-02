#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;
t_vector	new_vector(double x, double y, double z);
t_vector	substract_vector(t_vector vec1, t_vector vec2);
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_mul(t_vector vec1, double k);
t_vector	vec_cross(t_vector vec1, t_vector vec2);
double		vec_length(t_vector vec);
t_vector	vec_normolize(t_vector vec);
double		vec_scolar(t_vector vec1, t_vector vec2);
t_vector	vec_del(double k, t_vector vec);

#endif