#ifndef PIMP_COLOR_H
#define PIMP_COLOR_H

// Unsigned char etant long a ecrire, on contracte en t_uchar.
typedef unsigned char t_uchar;

// Du fait que la MLX est en BGRA, il faut re-orienter notre couleur en RGBA.
#define RED_COMP 2
#define GREEN_COMP 1
#define BLUE_COMP 0
#define ALPHA_COMP 3

typedef struct	s_color
{
	t_uchar r;
	t_uchar g;
	t_uchar b;
	t_uchar a;
}				t_color;

t_color create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a);
t_color *malloc_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a);
void destroy_color(t_color to_destroy);
void free_color(t_color *to_free);

// Permet de fusionner deux couleurs (actual et to_add).
t_color fuze_color(t_color actual, t_color to_add);

#endif
