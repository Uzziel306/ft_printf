#include "ft_printf.h"

int      ft_s_dat(t_pf *f, char *str)
{
  int    i;

  i = 0;
  if(f->tool.y == 0)
    return(0);
  while (str[i] != '\0' && i < f->tool.y)
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

int       ft_s_x_r(t_pf *f, char *str)
{
  f->tool.len = ft_strlen(str);
  if (f->tool.len >= f->tool.x)
    ft_putstr(str);
  else
  {
    f->tool.x -= f->tool.len;
    ft_putstr(str);
    while (f->tool.i < f->tool.x)
    {
      write(1, " ", 1);
      f->tool.i += 1;
    }
  }
  return (0);
}

int       ft_s_x_dat(t_pf *f, char *str)
{
  char *tmp;

// printf("x = %d, y = %d, dat = %d, minus = %d , len = %d\n",f->tool.x, f->tool.y, f->tool.dat, f->tool.minus, f->tool.len);
  tmp = ft_strdup(str);
  f->tool.len = ft_strlen(str);
  if (f->tool.y >= f->tool.len && f->tool.x <= f->tool.len)
    ft_putstr(str);
  else if (f->tool.x <= f->tool.y)
    ft_s_dat(f, str);
  else if (f->tool.x > f->tool.len && f->tool.minus == 0)
  {
    tmp[f->tool.y] = '\0';
    ft_s_x(f, tmp);
  }
  else if (f->tool.x > f->tool.len && f->tool.minus == 1)
  {
    tmp[f->tool.y] = '\0';
    ft_s_x_r(f, tmp);
  }
  else if (f->tool.y < f->tool.len)
  {
    tmp[f->tool.y] = '\0';
    ft_s_x_r(f, tmp);
  }
  return (0);
}

// printf("x = %d, y = %d, . = %d\n", f->tool.x, f->tool.y, f->tool.dat);
// '%' = x, '.' = y

int       ft_s(t_pf *f, char *str)
{
  int     i;

  f->tool.len = ft_strlen(str);
  i = 0;
  if (f->tool.dat == 0 && f->tool.x == 0 && f->tool.y == 0)
    ft_putstr(str);
  else if (f->tool.dat == 1 && f->tool.x == 0)
    ft_s_dat(f, str);
  else if (f->tool.dat == 0 && f->tool.x > 0 && f->tool.minus == 0 && f->tool.y == 0)
    ft_s_x(f, str);
  else if (f->tool.dat == 0 && f->tool.x > 0 && f->tool.minus == 1 && f->tool.y == 0)
    ft_s_x_r(f, str);
  else if (f->tool.dat == 1 && f->tool.x > 0 && f->tool.y > 0)
    ft_s_x_dat(f, str);
  return(0);
}
