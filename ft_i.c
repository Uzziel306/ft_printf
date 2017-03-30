#include "ft_printf.h"

int       ft_i_d(t_pf *f, char *str)
{
  if (f->t.plus == 1 && str[0] != '-')
    f->t.res += ft_putchar('+');
  if (str[0] == '-')
  {
    str += 1;
    f->t.res += ft_putchar('-');
    f->t.len -= 1;
  }
  while (f->t.len < f->t.y)
  {
    f->t.res += ft_putchar('0');
    f->t.len += 1;
  }
  f->t.res += ft_putstr(str);
  return (0);
}

int      ft_i_x(t_pf *f, char *str)
{
  char c = ' ';
  if (f->t.plus == 1 && str[0] != '-' && str[0] != '-')
  {
    f->t.res += ft_putchar('+');
    f->t.len += 1;
  }
  if (f->t.z == 1)
  {
    c = '0';
    f->t.res += ft_putchar('0');
    f->t.len += 1;
  }
  while (f->t.len < f->t.x)
  {
    f->t.res += ft_putchar(c);
    f->t.len += 1;
  }
  f->t.res += ft_putstr(str);
  return (0);
}

int       ft_i_x_complex(t_pf *f, char *str)
{
  if (f->t.s == 1)
    f->t.res += ft_putchar(' ');
  if (f->t.plus == 1 && str[0] != '-')
    str = ft_strjoin("+", str);
  while (f->t.len < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    f->t.len += 1;
  }

   f->t.res += ft_putstr(str);
   return (0);
}

int      ft_i_x_complex_1(t_pf *f, char *str)
{
  int     j;

  if (f->t.s == 1)
    f->t.res += ft_putchar(' ');
  if (str[0] == '-')
  {
    str += 1;
    f->t.res += ft_putchar('-');
    f->t.len -= 1;
    f->t.x -= 1;
  }
  j = f->t.y;
  if (f->t.plus == 1)
    j += 1;
  while (j < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    j++;
  }
    ft_i_d(f, str);
  return (0);
}

int        ft_i_x_r(t_pf *f, char *str)
{
  if (f->t.plus == 1 && f->t.z == 0 && str[0] != '-')
  {
    str = ft_strjoin("+", str);
    f->t.len += 1;
  }
  f->t.res += ft_putstr(str);
  while (f->t.len < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    f->t.len += 1;
  }
  return (0);
}

int       ft_i_x_complex_2(t_pf *f, char *str)
{
  if (f->t.s == 1)
    f->t.res += ft_putchar(' ');
  ft_i_d(f, str);
  while (f->t.y < f->t.x)
  {
    f->t.res += ft_putchar(' ');
    f->t.y += 1;
  }
  return (0);
}

int       ft_i_print(t_pf *f, char *str)
{
  if (f->t.s == 1 && str[0] != '-')
    f->t.res += ft_putchar(' ');
  if (f->t.plus == 1 && f->t.m == 0 && str[0] != '-')
      f->t.res += ft_putchar('+');
    f->t.res += ft_putstr(str);
  return (0);
}

int       ft_i_2(t_pf *f, char *str)
{
  if (f->t.z == 123454)
    f->t.res += ft_putstr("Tu mama en tangota");
  else if (f->t.dat == 1 && f->t.len >= f->t.y && f->t.x == 0)//dat sencillo
    return (ft_i_print(f, str));
  else if (f->t.dat == 1 && (f->t.len - 1) < f->t.y && f->t.x == 0) //dat sencillo
    return (ft_i_d(f, str));
  else if (f->t.dat == 0 && f->t.y == 0 && f->t.x > 0 && f->t.m == 0) // x sencillo
    return (ft_i_x(f, str));
  else if (f->t.dat == 0 && f->t.y == 0 && f->t.x > 0 && f->t.m == 1) // x sencillo
    return (ft_i_x_r(f, str));
  else if (f->t.x <= f->t.len && f->t.y > f->t.len)
    return (ft_i_d(f, str));
  else if (f->t.y <= f->t.len && f->t.x <= f->t.len) //complex X y Y menor o igual que len
    return (ft_i_print(f, str));
  else if (f->t.y < f->t.len && f->t.x >= f->t.len) //complex X > len
    return (ft_i_x_complex(f, str));
  else if (f->t.y >= f->t.len && f->t.x > f->t.len && f->t.m == 0) //complex X > len
    return (ft_i_x_complex_1(f, str));
  else if (f->t.y >= f->t.len && f->t.x > f->t.len && f->t.m == 1) //complex X > len
    return (ft_i_x_complex_2(f, str));
  zero(f);
  return (0);
}

int       ft_i(t_pf *f, int nb)
{
  char    *str;

  str = ft_itoa(nb);
  f->t.len = ft_strlen(str);
  // printf("x = %d, y = %d, len = %d, zero = %d \n", f->t.x, f->t.y, f->t.len, f->t.z);
  if (f->t.m == 0 && f->t.fnb == 0 && f->t.dat == 0 && f->t.z == 0)
    return(ft_i_print(f, str));
  else if (f->t.dat == 1 && f->t.x == 0 && f->t.y == 0)
    {
      zero(f);
      return (0);
    }
  return (ft_i_2(f, str));
}
