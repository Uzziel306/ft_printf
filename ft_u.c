#include "ft_printf.h"

void			u_putnbr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int				ft_u(t_pf *f, va_list pa)
{

	unsigned int i;
	int count;
	int flag;

	i = (unsigned int)va_arg(pa, int);
	u_putnbr(i);
	count = 1;
	flag = 0;
	while (flag == 1 || (i / 10 > 0 && flag == 0))
	{
		i = i / 10;
		count++;
	}
	return (f->t.res += count);
}

int            ft_digitnuml(int n, int base)
{
    int        i;

    i = 0;
    while ((n = n / base))
        i++;
    return (i + 1);
}

char    *ft_itoa_basel(unsigned long long int n, int b)
{
    char    *num;
    size_t    size;
    long long int neg;
    long long int mod;

    neg = 0;
    size = ft_digitnuml(n, b);
		num = ft_strnew(size);
    num[size + neg] = 0;
    while (size--)
    {
        mod = (n % b);
        num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
        n /= b;
    }
    return (num);
}

int ft_o(t_pf *f, va_list pa)
{
	unsigned long long int i;

	i = va_arg(pa, unsigned long long int);
	if (f->t.ht == 1 && i != 0)
		f->t.res += ft_putchar('0');
	f->t.nb = ft_itoa_basel(i, 8);
  return (f->t.res += ft_putstr(f->t.nb));
}
