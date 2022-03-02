#ifndef PARSER_H
# define PARSER_H

void		parse_type(t_rt *scene);
t_color		split_rgb(char *rgb, t_rt *scene);
t_vector	str_to_vec(char *str, t_rt *scene);
void		parse_rt(char *file_name, t_rt *scene);
void		parse_res(t_rt *scene);
void		parse_ambient(t_rt *scene);
void		parse_camera(t_rt *scene);
void		parse_light(t_rt *scene);
void		parse_sphere(t_rt *scene);
void		parse_plane(t_rt *scene);
void		parse_square(t_rt *scene);
void		parse_triangle(t_rt *scene);
void		parse_cylindre(t_rt *scene);
int			obj_count(t_list *obj);
char		**split_clear(char **split);
int			count_split(char **split);

#endif