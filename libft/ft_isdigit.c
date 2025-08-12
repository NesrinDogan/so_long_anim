#include "libft.h"

int    ft_isdigit(int c)
{
    /* this checks the character c is '0' to '9' (a decimal digit) */
    return (c >= 48 && c <= 57);
}
