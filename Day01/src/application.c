#include "pimp.h"

t_application create_application(int size_x, int size_y, char *title)
{
	t_application result;

	result.mlx_ptr = mlx_init();
	result.size = create_vector2(size_x, size_y);
	result.win_ptr = mlx_new_window(result.mlx_ptr, result.size.x, result.size.y, title);
	result.image = malloc_image(result.mlx_ptr, result.size.x, result.size.y);
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
	free_image(to_destroy.image, to_destroy.mlx_ptr);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

void free_application(t_application *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}

void clear_application(t_application *app, t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < app->size.x)
	{
		j = 0;
		while (j < app->size.y)
		{
			put_pixel(app->image, i, j, color);
			j++;
		}
		i++;
	}
}

void render_application(t_application *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->image->img_ptr, 0, 0);
}
