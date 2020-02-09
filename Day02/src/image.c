#include "pimp.h"

// Creer une structure sur la stack
t_image	create_image(int size_x, int size_y)
{
	t_image result;

	result.size = create_vector2(size_x, size_y);
	result.img_ptr = mlx_new_image(g_app->mlx_ptr, result.size.x, result.size.y);
	result.pixels = mlx_get_data_addr(result.img_ptr,
									&(result.bits_per_pixel),
									&(result.size_line),
									&(result.endian));
	return (result);
}

// Creer une structure dans la heap
t_image	*malloc_image(int size_x, int size_y)
{
	t_image *result;

	result = malloc(sizeof(t_image));
	if (result == NULL)
		return (NULL);
	*result = create_image(size_x, size_y);
	return (result);
}

void destroy_image(t_image to_destroy)
{
	// 1 - On detruit l'interieur de to_destroy
	mlx_destroy_image(g_app->mlx_ptr, to_destroy.img_ptr);
	// Ne pas free to_destroy.pixels. Ca fait planter la mlx
}

void free_image(t_image *to_free)
{
	// 1 - On detruit l'interieur de to_free
	destroy_image(*to_free);
	// 2 - on detruit to_free
	free(to_free);
}
