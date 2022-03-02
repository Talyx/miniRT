#ifndef RAY_TRAYCING_H
# define RAY_TRAYCING_H

typedef struct s_vplane
{
	double	width;
	double	hight;
	double	x_pixel;
	double	y_pixel;
}				t_vplane;

typedef struct s_ray
{
	int			mlx_x;
	int			mlx_y;
	int			color;
	double		y_ray;
	double		x_angle;
	double		y_angle;
}				t_ray;

typedef struct s_triangl
{
	t_vector	e1;
	t_vector	e2;
	t_vector	p_vec;
	t_vector	t_vec;
	t_vector	q_vec;
	double		det;
	double		u;
	double		v;
	double		inv_det;
	double		result;
}				t_triangl;

typedef struct s_point
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
}				t_point;

typedef struct s_cylind
{
	t_vector	cam_cylin;
	t_discr		di;
	t_discr		pl;
	t_discr		res;
	t_vector	sur;
	t_vector	p1;
	t_vector	p2;
	t_obj		*pl1;
	t_obj		*pl2;
	double		m;
}				t_cylind;

typedef struct s_calc
{
	t_vector	n;
	t_color		ambient;
	t_color		result;
	t_vector	p;
}			t_calc;

void		ray_traycing(t_rt *scene);
t_vplane	*get_view_plane(t_rt *scene, double width,
				double hight, double fov);
double		figure_intersect(t_vector origin, t_vector ray, t_obj *obj);
t_obj		*new_plane(t_vector point, t_vector orient, t_color color);
t_discr		sphere_intersection(t_vector origin, t_vector ray, t_obj *obj);
double		plane_intersection(t_vector origin, t_vector ray, t_obj *plane);
double		square_intersection(t_vector origin, t_vector ray, t_obj *square);
double		triangle_intersection(t_vector origin, t_vector ray,
				t_obj *triangle);
t_discr		cylinder_intersection(t_vector origin, t_vector ray,
				t_obj *cylinder, double set);
int			shadow_sphere_intersection(t_vector origin, t_vector ray,
				t_obj *obj);
void		create_cams(t_rt *scene);
int			rgb_to_int(t_color color);
int			get_color(t_rt *scene, t_vector ray);
void		ray_traycing(t_rt *scene);
void		cam_norm(t_camera *cam);
double		get_m(t_obj *cylinder, t_discr di,
				t_vector cam_cylinder, t_vector ray);
t_discr		get_dsqrt(t_vector ray, t_obj *cylinder, t_vector cam_cylinder);
void		set_tube(t_vector sur, t_obj *cylinder, t_vector pl_pos, double m);
int			check_dirction(t_vector vec);

#endif