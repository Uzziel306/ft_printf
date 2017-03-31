#include "ft_printf.h"

int     ft_c_n(t_pf *f, char c)
{
  int   i;

  i = 1;
  while(i < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    i++;
  }
  f->t.res += ft_putchar(c);
  return (0);
}

int     ft_c_n_r(t_pf *f, char c)
{
  int   i;

  i = 1;
  f->t.res += ft_putchar(c);
  while(i < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    i++;
  }
  return (0);
}

int     ft_c(t_pf *f, int c)
{
  // f->t.dat_nb = 0;
  if (f->t.x == 0)
    f->t.res += ft_putchar(c);
  else if (f->t.x != 0 && f->t.m == 0)
    ft_c_n(f, c);
  else if (f->t.x != 0 && f->t.m == 1)
    ft_c_n_r(f, c);
  zero(f);
  return (0);
}
