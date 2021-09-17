#include <stdio.h>

int     ft_convdec(int value)
{
    int pow;
    int dec;
    int modulo;

    pow = 1;
    dec = 0;
    modulo = 0;
    while (value > 0)
    {
        modulo = value % 10;
        if (modulo == 1)
            dec += pow;
        value /= 10;
        pow *= 2;
    }
    return (dec);
}

int main (void)
{
    int bi;

    bi = 1111011;

    printf("%c\n",ft_convdec(bi));
}


/*127 / 128  0
127 / 64   1
63 / 32    1
31 / 16     1
15 / 8      1
7   / 4      1
3   /2      1
1   / 1     1*/