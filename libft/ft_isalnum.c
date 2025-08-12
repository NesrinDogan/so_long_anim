#include "libft.h"

int    ft_isalnum(int c)
{
    /* This checks character c is alphabetic or decimal digit */
    return (ft_isalpha(c) || ft_isdigit(c));
}
