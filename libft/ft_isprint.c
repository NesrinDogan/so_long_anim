#include "libft.h"

int    ft_isprint(int c)
{
    /* check if c is between decimal 32 and decimal 126 (inclusive) */
    return (c >= 32 && c <= 126);
}
