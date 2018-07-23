/*
** EPITECH PROJECT, 2018
** all functions
** File description:
** source file
*/

#include "malloc.h"
#include <stdlib.h>

const void *heap_address = NULL;

void	free(void *ptr)
{
	t_my_block	*block;

	if (heap_address != NULL) {
		if (ptr > heap_address && ptr < sbrk(0)) {
			block = get_memory_address(ptr);
			block->free_value = 1;
			heap_address = NULL;
			brk(block);
			brk(ptr);
		}
	}
}

t_my_block	*check_memory(t_my_block *last, t_my_block *res, size_t size)
{
	if (heap_address != NULL) {
		last = (t_my_block *)heap_address;
		res = block_checking(&last, size);
		if (res != NULL) {
			if ((res->size - size) >= (METADATA_SIZE + 4))
				divise_memory(res, size);
			res->free_value = 0;
		}
		res = grow_memory(last, size);
		if (res == NULL)
			return (NULL);
	}
	res = grow_memory(NULL, size);
	return (res);
}

void	*malloc(size_t size)
{
	t_my_block	*res, *last;
	size_t	size_tmp;

	if (size == 0)
		return (NULL);
	size_tmp = align_pointer(size);
	res = check_memory(last, res, size_tmp);
	if (res == NULL)
		return (NULL);
	heap_address = res;
	return (res->meta_data);
}

void	*realloc(void *ptr, size_t size)
{
	t_my_block	*res;
	void		*new_ptr;

	if (size == 0 && ptr) {
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	res = get_memory_address(ptr);
	if (res->size >= align_pointer(size))
		return (ptr);
	new_ptr = malloc(align_pointer(size));
	if (new_ptr) {
		memcpy(new_ptr, ptr, res->size);
		free(ptr);
		}
	return (new_ptr);
}
