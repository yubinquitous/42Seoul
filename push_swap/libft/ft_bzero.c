#include "libft.h"

void ft_bzero(void *s, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        *(unsigned char *)(s + i) = 0;
        ++i;
    }
}