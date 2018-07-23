/*
** EPITECH PROJECT, 2018
** show allocated memory
** File description:
** show memory
*/

#include "malloc.h"
#include <stdlib.h>

void			error_on_memory(void)
{
	__ERROR_MEMORY__;
	exit(ERROR_EXIT);
}

void			show_alloc_mem(void)
{
	t_my_block	*res;
	void		*addr;

	res = (t_my_block *)heap_address;
	addr = sbrk(0);
	printf("break : %p\n", addr);
	if (res == NULL)
		error_on_memory();
	while (res != NULL) {
		if (res->free_value == 0) {
			printf("%p", &res->meta_data);
			printf(" - %p", &res->meta_data + res->size);
			printf(" : %li bytes\n", res->size);
		}
		res = res->next;
	}
}
