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
		if (f->t.ht == 1)
			f->t.res += ft_putchar('0' && nb != 0);
		f->t.nb = ft_itoa_base(nb, 8);
    return (f->t.res += ft_putstr(f->t.nb));
}
