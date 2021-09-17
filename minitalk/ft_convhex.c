#include <stdio.h>


void    ft_convhex(int value, char *hex)
{
    char    *base;
    char    *start;
    int     nb; 

    base = "0123456789ABCDEF";
    start = "/u00";
    nb = 0;
    while (nb <= 4)
    {
        hex[nb] = start[nb];
        nb++;
    }
    hex[5] = base[value % 16];
    hex[4] = base[value / 16];
    hex[6] = '\0';

}
int main (void)
{
    int value;
    char hex[6];

    value = 160;
    ft_convhex(value, hex);
    printf("%s\n", hex);

}