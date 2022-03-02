#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# define T_MIN 0
# define T_MAX INFINITY
# define SPHERE 0
# define PLANE  1
# define SQUARE 2
# define TRIANGLE 3
# define CYLINDRE 4

typedef struct s_obj
{
	int			id;
	double		ratio;
	double		diametr;
	double		height;
	double		closes_t;
	t_vector	point;
	t_vector	point2;
	t_vector	point3;
	t_color		color;
	t_vector	orient;
	t_vector	n;
	t_discr		discr;
}				t_obj;

typedef struct s_rt
{
	char		*line;
	char		**split;
	int			obj_count;
	int			camera_count;
	int			cam_index;
	void		*mlx;
	void		*window;
	t_vector	p;
	t_obj		*obj;
	t_list		*obj_list;
	t_list		*cam_list;
	t_list		*light_list;
	t_res		res;
	t_ambient	ambient;
	t_camera	*cam;
	int			light;
	int			save;
}				t_rt;

void		my_pixel_put(t_rt *scene, int x, int y, int color);
void		switch_cam(t_rt *scene);
int			finish_programm(int keycode, t_rt *scene);
int			change_cam(int keycode, t_rt *scene);
void		get_cur_cam(t_rt *scene);
void		bitmap_fileheader(t_rt *scene, int p_size, int fd);
void		bitmap_infoheader(t_rt *scene, int fd);
void		create_bmp(t_rt *scene);
void		clean_cam(t_rt *scene);
void		clean(t_rt *scene);
void		print_vector(t_vector vec, char *str);
double		shad_spher(t_discr sqr);
t_vector	get_ray(t_rt *scene, double ray_x, double ray_y);
int			check_color(char **rgb);
int			get_length_dir(char *dir);

#endif