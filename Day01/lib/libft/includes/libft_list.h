#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

typedef void (*destroy_funct)(void *to_destroy);

typedef struct	s_list
{
	void		***content;
	size_t		size;
	size_t		max_size;
	size_t		nb_line;
	size_t		push_size;
}				t_list;

t_list		create_list(size_t p_push_size);
t_list		*malloc_list(size_t p_push_size);
void		destroy_list(t_list to_destroy, destroy_funct funct);
void		free_list(t_list *to_free, destroy_funct funct);
t_vector2	list_calc_index_coord(t_list *list, size_t index);
void		list_push_back(t_list *list, void *to_add);
void		*list_at(t_list *list, size_t index);
void		**list_get(t_list *list, size_t index);

#endif
