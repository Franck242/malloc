/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** header
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <pthread.h>

# define SUCCESS_EXIT (0)
# define ERROR_EXIT (84)
# define __ERROR_MESSAGE__ write(STDERR_FILENO, "ERROR in memory allowed\n", 25)
# define __ERROR_FREE__ write(STDERR_FILENO, "ERROR in free command\n", 22)
# define __ERROR_SBRK__ write(STDERR_FILENO, "ERROR, the sbrk fails.\n", 24)
# define __ERROR_SIZE__ write(STDERR_FILENO, "ERROR, invalid size\n", 20)
# define __ERROR_MEMORY__ write(STDERR_FILENO, "ERROR in memory zone\n", 21)
# define __ERROR_ADRESS__ write(STDERR_FILENO, "ERROR, invalid address\n", 23);
# define align_pointer(size) (((((size)-1)>>2)<<2)+4)
# define METADATA_SIZE sizeof(void*) + 12

const void *heap_address;

typedef struct				s_my_block
{
	struct s_my_block		*next;
	size_t				size;
	int				free_value;
	char				meta_data[1];
	void				*ptr;
}					t_my_block;

t_my_block	*block_checking(t_my_block **last, size_t size);
t_my_block	*grow_memory(t_my_block *last, size_t size);
void		divise_memory(t_my_block *block, size_t size);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		show_alloc_mem();
void		*get_memory_address(void *ptr);
void		*calloc(size_t nb, size_t size);

#endif /* MALLOC_H_ */
