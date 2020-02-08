#include "pimp.h"

typedef struct s_vector2
{
	int x; // 4 octets
	int y; // 4 octets
}				t_vector2; // La structure fait donc 8 octets
							// La taille d'un pointeur est de 8 octets

t_vector2		create_vector2(int p_x, int p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2		*malloc_vector2(int p_x, int p_y)
{
	t_vector2 *result;

	result = malloc(sizeof(t_vector2));
	if (result == NULL)
		return (NULL);
	*result = create_vector2(p_x, p_y);
	return (result);
}

void			destroy_vector2(t_vector2 to_destroy)
{
	(void)to_destroy;
}

void			free_vector2(t_vector2 *to_free)
{
	destroy_vector2(*to_free);
	free(to_free);
}

void print_vector2(t_vector2 to_print)
{
	printf("(%d / %d)\n", to_print.x, to_print.y);
}

int main()
{
	t_vector2 *ptr_tmp;
	int i;

	ptr_tmp = malloc_vector2(10, 20);
	i = ((int *)ptr_tmp)[2];
	printf("%d\n", i);
	return (0);
}
