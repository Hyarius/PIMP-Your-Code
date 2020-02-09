#include "pimp.h"

t_application create_application(int size_x, int size_y, char *title)
{
	t_application result;

	// Recupere le retour de mlx_init (tableau de ptr sur fonctions)
	result.mlx_ptr = mlx_init();

	// Stocke sixe_x et size_y dans result
	result.size = create_vector2(size_x, size_y);

	// Creation d'une nouvelle fenetre et renvoie un pointeur sur cette fenetre
	result.win_ptr = mlx_new_window(result.mlx_ptr, result.size.x, result.size.y, title);

	// Malloc le contenu de la new window
	result.image = NULL;
	//result.image = malloc_image(result.size.x, result.size.y);

	return (result);
}

t_application *malloc_application(int size_x, int size_y, char *title)
{
	t_application *result;

	result = malloc(sizeof(t_application));
	if (result == NULL)
		return (NULL);
	*result = create_application(size_x, size_y, title);
	return (result);
}

void destroy_application(t_application to_destroy)
{
	free_image(to_destroy.image);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

void free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}

void application_create_content()
{
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

void clear_application(t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < g_app->size.x)
	{
		j = 0;
		while (j < g_app->size.y)
		{
			put_pixel(g_app->image, i, j, color);
			j++;
		}
		i++;
	}
}

void render_application()
{
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->image->img_ptr, 0, 0);
}
