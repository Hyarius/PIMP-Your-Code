#include "pimp.h"

t_color		create_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a)
{
	t_color result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

t_color *malloc_color(t_uchar p_r, t_uchar p_g, t_uchar p_b, t_uchar p_a)
{
	t_color *result;

	result = (t_color*)malloc(sizeof(t_color));
	if (result == NULL)
		return (NULL);
	*result = create_color(p_r, p_g, p_b, p_a);
	return (result);
}

void destroy_color(t_color to_destroy)
{
	// TODO: Ecrire message dans logfile
	(void)to_destroy;
}

void free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}

//Permet de fusionner deux couleurs en une seule, grace a l'alpha.
t_color fuze_color(t_color actual, t_color to_add)
{
	t_color result;
	float new_alpha;
	float inv_alpha;

	/*

	Le but de la fonction : Fusionner 2 couleurs en fonction de la
							transparence de la seconde

	entree de la fonction :
	1 - La couleur ACTUELLEMENT en place -> la couleur dessous -> actual
	2 - La couleur a ajouter -> la couleur dessus -> to_add

	Retour de la fonction :
	La couleur une fois fusionnee

	couleur finale = (X% de la couleur a ajouter) + (100 - X% de la couleur de base)

	*/

	// 1 ) Calcul de X -> new_alpha
	new_alpha = to_add.a / 255.0f;

	// 2 ) Calcul de 100 - X -> inv_alpha
	inv_alpha = 1.0f - new_alpha;

	// 3 ) Application de la formule
	result = create_color(
		actual.r * inv_alpha + to_add.r * new_alpha,
		actual.g * inv_alpha + to_add.g * new_alpha,
		actual.b * inv_alpha + to_add.b * new_alpha,
		// On met la transparence de la couleur finale a 255, car c'est la
		//couleur de notre futur pixel
		255
	);
	return (result);
}
