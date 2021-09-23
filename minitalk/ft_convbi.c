#include <unistd.h>
#include <stdio.h>

int     ft_binary(int value)
{
    int nb;
    int power;
    int div;

    nb = 0;
    power = 10000000;
    div = 128;
    while (value > 0)
    {
        nb += (value / div) * power;
        value = value % div;
        div /= 2;
        power /= 10;
    }
    return (nb);
}

int main ()
{
    int value;

    value = 0;
    while (value < 128 )
    {
           printf("%d = %d\n",value ,ft_binary(value));
           value++;
    }
}
    /*for(int c = 0; c<255 ;c++)
    {
        printf("%d = %lc\n",c, c);
    }*/
    //const char * nb = "\u00A5";

/*int    ft_strlen (const char *nb)
{
    int a = 0;
    while(*nb)
    {
        *nb++;
        a++;
    }
    return (a);
}

    write(1,nb,ft_strlen(nb));
    //printf("%s\n","\u0101");
}
*/

/*127 / 128  0
127 / 64   1
63 / 32    1
31 / 16     1
15 / 8      1
7   / 4      1
3   /2      1
1   / 1     1*/