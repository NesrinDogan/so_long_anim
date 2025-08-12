#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char    *ptr;

    ptr = (char *) s;
    while (n > 0)
    {
        *(ptr++) = 0;
         n--;
    }
}
