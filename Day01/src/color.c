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
t_color fuze_color(t_color base, t_color new)
{
	t_color result;
	float new_alpha;
	float inv_alpha;

	new_alpha = new.a / 255.0f;
	inv_alpha = 1.0f - new_alpha;
	result = create_color(
		base.r * inv_alpha + new.r * new_alpha,
		base.g * inv_alpha + new.g * new_alpha,
		base.b * inv_alpha + new.b * new_alpha,
		255
	);
	return (result);
}
