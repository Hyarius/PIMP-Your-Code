#ifndef PIMP_IMAGE_H
#define PIMP_IMAGE_H

typedef struct	s_image
{
	t_vector2	size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

t_image create_image(void *mlx_ptr, int size_x, int size_y);
t_image *malloc_image(void *mlx_ptr, int size_x, int size_y);
void destroy_image(t_image to_destroy, void *mlx_ptr);
void free_image(t_image *to_free, void *mlx_ptr);

#endif
