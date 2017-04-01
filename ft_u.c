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

int ft_o(t_pf *f, int nb)
{
    int o_nb;
    int i;
		char *str;

    o_nb = 0;
    i = 1;
    while (nb != 0)
    {
        o_nb += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
		str = ft_itoa(o_nb);
    return (f->t.res += ft_putstr(str));
}
