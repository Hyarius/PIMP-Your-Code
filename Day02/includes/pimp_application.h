#ifndef PIMP_APPLICATION_H
#define PIMP_APPLICATION_H

typedef struct	s_application
{
	// - Le retour de mlx_init() -> correspond a un tableau de pointeur de
	//		fonctions dans la MLX (A ne pas toucher).
	void		*mlx_ptr;

	// - Le retour de mlx_new_window() -> correspond a la fenetre a l'ecran.
	void		*win_ptr;

	// - La taille la fenetre en pixels.
	t_vector2	size;

	// - Le contenu de la fenetre.
	t_image		*image;
}				t_application;

// Cree une t_application sur la stack.
t_application create_application(int size_x, int size_y, char *title);

// Cree une t_application sur la heap (malloc).
t_application *malloc_application(int size_x, int size_y, char *title);

// Appelle mlx_destroy_window(), puis free_image().
void destroy_application(t_application to_destroy);

// Appelle la fonction destroy_application(), puis free to_free.
void free_application(t_application *to_free);

// Met l'entierete de l'image a la couleur de color.
void clear_application(t_color color);

// Affiche a l'ecran le contenu de la fenetre. (fait appel a mlx_put_image_to_window())
void render_application();

void application_create_content();

#endif
