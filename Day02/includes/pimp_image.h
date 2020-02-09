#ifndef PIMP_IMAGE_H
#define PIMP_IMAGE_H

typedef struct	s_image
{
	// La taille de l'image exprimee en pixels.
	t_vector2	size;

	// Le retour de mlx_new_image().
	void		*img_ptr;

	// Pointeur sur les chars composant les pixels de l'image.
	// (retour de mlx_get_data_addr())
	char		*pixels;

	// Les trois int suivants sont obtenus a travers mlx_get_data_addr().

	// Nombre de bits d'un pixel (dans notre cas, 8x4).
	int			bits_per_pixel;

	// Longueur en chars d'une ligne.
	int			size_line;

	// Si egal a 0 : big endian, si egal a 1 : little endian (a verifier).
	int			endian;
}				t_image;

t_image create_image(int size_x, int size_y);
t_image *malloc_image(int size_x, int size_y);
void destroy_image(t_image to_destroy);
void free_image(t_image *to_free);

#endif
