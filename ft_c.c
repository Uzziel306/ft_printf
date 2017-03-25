#include "ft_printf.h"

int     ft_c_n(t_pf *f, char c)
{
  int   i;

  i = 1;
  while(i < f->tool.x)
  {
    write(1, " ",  1);
    i++;
  }
  ft_putchar(c);
  return (0);
}

int     ft_c_n_r(t_pf *f, char c)
{
  int   i;

  i = 1;
  ft_putchar(c);
  while(i < f->tool.x)
  {
    write(1, " ",  1);
    i++;
  }
  return (0);
}

int     ft_c(t_pf *f, int c)
{
  // f->tool.dat_nb = 0;
  if (f->tool.x == 0)
    ft_putchar(c);
  else if (f->tool.x != 0 && f->tool.minus == 0)
    ft_c_n(f, c);
  else if (f->tool.x != 0 && f->tool.minus == 1)
    ft_c_n_r(f, c);
  return (0);
}
