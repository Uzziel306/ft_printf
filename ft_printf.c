#include "ft_printf.h"

int       ft_chose_format(t_pf *f, va_list pa)
{
  if (f->tool.c == 's')
    ft_s(f, va_arg(pa, char*));
  if (f->tool.c == 'i')
    ft_i(f, va_arg(pa, int));
  return (0);
}

void      zero(t_pf *f)
{
  f->tool.i = 0;
  f->tool.j = 0;
  f->tool.k = 0;
  f->tool.ret = 0;
  f->tool.len = 0;
  f->tool.x = 0;
  f->tool.y = 0;
  f->tool.minus = 0;
  f->tool.dat = 0;
  f->tool.dat_nb = 0;
  f->tool.c = ' ';
  f->tool.nb = ft_strnew(0);
  f->tool.nb2 = ft_strnew(0);
}

char      ft_get_format(char c)
{
  char    format[14] = "sSpdDioOuUxXcC";
  int     i;

  i = 0;
  while(format[i] != '\0')
  {
    if (format[i] == c)
      return (c);
    i++;
  }
  return (0);
}

void    ft_get_nb(t_pf *f, int flag, char **str)
{
  if (flag == 1)
  {
    f->tool.nb[f->tool.j] = **str;
    f->tool.y = ft_atoi(f->tool.nb);
    f->tool.j += 1;
  }
  else
  {
    f->tool.nb2[f->tool.k] = **str;
    f->tool.x = ft_atoi(f->tool.nb2);
    f->tool.k += 1;
  }
}

int     ft_getval(char **str, t_pf *f, va_list pa)
{
  while(**str)
  {
    if (**str == '.')
      f->tool.dat = 1;
    else if (**str == '-')
      f->tool.minus = 1;
    else if (**str == '0' && ((*(*str - 1)) == '%'))
      f->tool.zero = 1;
    else if (ft_isdigit(**str) && f->tool.dat != 0)
      ft_get_nb(f, 1, str);
    else if (ft_isdigit(**str) && f->tool.dat != 1)
      ft_get_nb(f, 2, str);
    else if ((f->tool.c = ft_get_format(**str)))
      return (ft_chose_format(f, pa));
    *str += 1;
  }
  return (0);
}

int       ft_printf(const char *format, ...)
{
  t_pf    *f;
  va_list pa;
  char    *str;
  va_start(pa, format);
  str = ft_strdup(format);
  if (!(f = (t_pf*)malloc(sizeof(t_pf))))
    ft_putstr("Error allocating memory\n");
  zero(f);
  while(*str)
  {
    if (*str == '%')
      ft_getval(&str, f, pa);
    else
      write(1,str,1);
    str++;
  }
  va_end(pa);
  return (0);
}

int main(void)
{
   printf("%-5.2s is a string\n", "");
   ft_printf("%-5.2s is a string\n", "");
  return 0;
}
