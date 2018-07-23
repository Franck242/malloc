/*
** EPITECH PROJECT, 2018
** calloc
** File description:
** source file
*/

#include "malloc.h"

void	*calloc(size_t nb, size_t size)
{
	void	*ptr;
	size_t	size_tmp;
	int	div_size;

	if (nb <= 0 || size <=0)
		return (NULL);
	size_tmp = size * nb;
	div_size = size_tmp / nb;
	if (size != div_size)
		return (NULL);
	ptr = malloc(size_tmp);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, size_tmp);
	return (ptr);
}
