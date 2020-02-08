#include "pimp.h"

int handle_key(int key, void *param)
{
	if (key == ESC_KEY)
		exit(0);

	return (0);
}

void put_pixel(t_image *image, int x, int y, t_color color)
{
	t_color actual;
	t_color tmp;
	int pixel_index;

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

void draw_rectangle(t_application *app, t_vector2 pos, t_vector2 size, t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			put_pixel(app->image, i + pos.x, j + pos.y, color);
			j++;
		}
		i++;
	}
}

int main()
{
	t_application *app;

	//Malloc une application.
	app = malloc_application(840, 680, "Title");

	//Clear et rempli d'une couleur donnee.
	clear_application(app, create_color(50, 50, 50, 255));

	//Dessine un rectangle a une position donnee, d'une taille donnee, dans une couleur donnee.
	draw_rectangle(app, create_vector2(50, 50), create_vector2(150, 50), create_color(255, 0, 0, 255));
	draw_rectangle(app, create_vector2(75, 75), create_vector2(150, 50), create_color(0, 0, 255, 125));

	//Affiche l'image dams la fenetre.
	render_application(app);
	//Boucle et attends les events.
	mlx_loop(app->mlx_ptr);
	return (0);
}
