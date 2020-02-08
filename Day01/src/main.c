#include "pimp.h"

typedef struct s_vector2
{
	int x;
	int y;
}				t_vector2;

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

int main()
{
	printf("Hello world\n");
	return (0);
}
