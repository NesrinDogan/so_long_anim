#include "libft.h"

int    ft_isascii(int c)
{
    /* checking if c is between 0 and decimal 127 */
    return (c >= 0 && c <= 127);
}
