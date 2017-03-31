#include "libft.h"

int            ft_digitnum(int n, int base)
{
    int        i;

    i = 0;
    while ((n = n / base))
        i++;
    return (i + 1);
}

char    *ft_itoa_base(int n, int b)
{
    char    *num;
    size_t    size;
    int        neg;
    int        mod;

    neg = 0;
    size = ft_digitnum(n, b);
    if (n < 0 && b == 10)
        neg++;
    num = ft_strnew(size);
    if (neg)
        num[0] = '-';
    num[size + neg] = 0;
    while (size--)
    {
        mod = ((n % b) < 0 ? -(n % b) : (n % b));
        num[size + neg] = ((mod > 9) ? mod + 87 : mod + '0');
        n /= b;
    }
    return (num);
}
