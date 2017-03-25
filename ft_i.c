#include "ft_printf.h"

void      ft_i(t_pf *f, int nb)
{
  // printf("%d\n", nb);
  f->tool.dat_nb = 0;
  ft_putnbr(nb);
}
