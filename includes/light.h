#ifndef LIGHT_H
# define LIGHT_H

t_color		color_add(t_color col1, t_color col2);
t_color		color_mul(t_color col1, t_color col2);
t_color		color_mul_nbr(double ratio, t_color color);
t_color		compute_lighting(t_rt *scene, t_vector n, t_vector ray, t_vector p);
t_color		color_del(double k, t_color vec);
t_color		calculate_elem(t_rt *scene, t_vector ray);
t_vector	get_vec_normal(t_rt *scene, t_vector p);
t_color		new_color(double r, double g, double b);
t_color		point_light(t_vector n, t_obj *light, t_vector p);
int			in_shadow(t_rt *scene, t_obj *light, t_vector ray);
double		shadow_inter(t_vector p, t_vector p_to_l,
				t_obj *figure, double vec_len);
double		get_closes(t_discr sqr);
#endif