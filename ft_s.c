#include "ft_printf.h"

int      ft_s_dat(t_pf *f, char *str)
{
  int    i;

  i = 0;
  if(f->tool.x == 0)
    return(0);
  while (str[i] != '\0' && i < f->tool.x)
  {
    write(1, &str[i] ,1);
    i += 1;
  }
  return (0);
}

int       ft_s_x(t_pf *f, char *str)
{
  f->tool.len = ft_strlen(str);
  if (f->tool.len >= f->tool.x)
    ft_putstr(str);
  else
  {
    f->tool.x -= f->tool.len;
    while (f->tool.i < f->tool.x)
    {
      write(1, " ", 1);
      f->tool.i += 1;
    }
    ft_putstr(str);
  }
  return (0);
}

int       ft_s(t_pf *f, char *str)
{
  int     i;

  i = 0;
  if (f->tool.dat == 0 && f->tool.x == 0)
    ft_putstr(str);
  else if (f->tool.dat == 1)
    ft_s_dat(f, str);
  else if (f->tool.dat == 0 && f->tool.x > 0 && f->tool.minus == 0)
    ft_s_x(f, str);
  return(0);
}
