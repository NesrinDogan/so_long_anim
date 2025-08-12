#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void    *ptr;
    size_t  total;

    total = count * size;
    if (count != 0 && total / count != size)
        return (NULL);
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total);
    return (ptr);
}
