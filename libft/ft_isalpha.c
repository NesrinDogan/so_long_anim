#include "libft.h"

int    ft_isalpha(int c)
{
    /* the first part of the condition checks 'A' to 'Z' */
    /* the second part of the condition checks 'a' to 'z' */
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
