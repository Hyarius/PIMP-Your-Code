#ifndef PIMP_DRAWING_H
#define PIMP_DRAWING_H

// Mettre sur image un pixel aux coordonees x et y de la couleur color.
void put_pixel(t_image *image, int x, int y, t_color color);

// Dessine dans app, a la position pos, d'une taille de size,
// un rectangle de couleur color. (Utile pour les elements temporaires)
void draw_rectangle(t_vector2 pos, t_vector2 size, t_color color);

// Dessine dans image, a la position pos, d'une taille de size,
// un rectangle de couleur color. (Utile pour les elements definitifs)
void draw_rectangle_in_image(t_image *image, t_vector2 pos, t_vector2 size, t_color color);

#endif
