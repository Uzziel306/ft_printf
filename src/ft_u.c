#include "ft_printf.h"

int				ft_u(t_pf *f, int nb)
{
	f->t.i = (unsigned int)nb;
	f->t.nb = ft_itoa(f->t.i);
	return (f->t.res += ft_putstr(f->t.nb));
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
