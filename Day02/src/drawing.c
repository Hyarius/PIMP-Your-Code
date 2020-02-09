#include "pimp.h"

void put_pixel(t_image *image, int x, int y, t_color color)
{
	t_color actual;
	t_color tmp;
	int pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return;

	pixel_index = (y * image->size.x + x) * 4;
	actual = create_color(
		image->pixels[pixel_index + RED_COMP],
		image->pixels[pixel_index + GREEN_COMP],
		image->pixels[pixel_index + BLUE_COMP],
		255
	);
	tmp = fuze_color(actual, color);
	image->pixels[pixel_index + RED_COMP] = tmp.r;
	image->pixels[pixel_index + GREEN_COMP] = tmp.g;
	image->pixels[pixel_index + BLUE_COMP] = tmp.b;
}

void draw_rectangle(t_vector2 pos, t_vector2 size, t_color color)
{
	draw_rectangle_in_image(g_app->image, pos, size, color);
}

void draw_rectangle_in_image(t_image *image, t_vector2 pos, t_vector2 size, t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			put_pixel(image, i + pos.x, j + pos.y, color);
			j++;
		}
		i++;
	}
}
