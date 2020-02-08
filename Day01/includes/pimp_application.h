#ifndef PIMP_APPLICATION_H
#define PIMP_APPLICATION_H

typedef struct	s_application
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector2	size;
	t_image		*image;
}				t_application;

t_application create_application(int size_x, int size_y, char *title);
t_application *malloc_application(int size_x, int size_y, char *title);
void destroy_application(t_application to_destroy);
void free_application(t_application *to_free);
void clear_application(t_application *app, t_color color);
void render_application(t_application *app);

#endif
