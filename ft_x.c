#include "ft_printf.h"

char        *ft_strinsrt(const char *dst, size_t n, const char *src)
{
    char    *str;

    if (!dst || (n > ft_strlen(dst)))
        return (0);
    str = ft_strnew(ft_strlen(dst) + ft_strlen(src));
    (void)ft_strncpy(str, dst, n);
    (void)ft_strcpy(str + n, src);
    return (ft_strcat(str, dst + n));
}

char    *ft_hextoa(int n, size_t prec)
{
    char    *hex;
    char    *num;
    char    *z;

    num = ft_itoa_base(n, 16);
    hex = num;
    if (prec)
    {
        z = ft_strnew(prec);
        (void)ft_memset(z, '0', prec);
        hex = ft_strinsrt(num, 0, z);
    }
    return (hex);
}

int   ft_x(t_pf *f, int nb)
{  if (f->t.ht == 1 && nb != 0 && f->t.c == 'x')
    f->t.res += ft_putstr("0X");
  else if (f->t.ht == 1 && nb != 0 && f->t.c == 'X')
    f->t.res += ft_putstr("0X");
  f->t.nb = ft_hextoa(nb, 0);
  return (f->t.res += ft_putstr(f->t.nb));
}
