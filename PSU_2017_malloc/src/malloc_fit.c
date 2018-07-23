/*
** EPITECH PROJECT, 2018
** malloc fit
** File description:
** pointers alignment
*/

#include "malloc.h"

t_my_block		*block_checking(t_my_block **last, size_t size)
{
	t_my_block	*res = (t_my_block *)heap_address;

	while (res != NULL) {
		if (res->free_value == 0 && res->size <= size)
			*last = res;
		res = res->next;
	}
	return (res);
}

t_my_block		*grow_memory(t_my_block *last, size_t size)
{
	t_my_block	*res;
	void		*ptr;

	res = sbrk(0);
	ptr = sbrk(METADATA_SIZE + size);
	if (last != NULL)
		last->next = res;
	if (ptr == (void*) -1) {
		__ERROR_SBRK__;
		return (NULL);
	}
	res->size = size;
	res->free_value = 0;
	res->next = NULL;
	return (res);
}

void			divise_memory(t_my_block *block, size_t size)
{
	t_my_block	*new_block;
	size_t		necessary_size;

	necessary_size = size - METADATA_SIZE;
	new_block = (t_my_block*)(block->meta_data + size);
	new_block->size = block->size - necessary_size;
	new_block->next = block->next;
	new_block->free_value = 1;
	block->size = size;
	block->next = new_block;
}

void            *get_memory_address(void *ptr)
{
	void            *res;
	size_t          size;

	size = METADATA_SIZE - 1;
	res = ptr - size;
	return (res);
}
