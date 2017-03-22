#include "ft_printf.h"

void      ft_chose_format(t_pf *f, va_list pa)
{

  if (f->tool.c == 's')
    ft_s(f, va_arg(pa, char*));
  if (f->tool.c == 'i')
    ft_i(f, va_arg(pa, int));
}
// va_arg(pa, char*)
void      zero(t_pf *f)
{
  f->tool.i = 0;
  f->tool.j = 0;
  f->tool.k = 0;
  f->tool.ret = 0;
  f->tool.len = 0;
  f->tool.x = 0;
  f->tool.minus = 0;
  f->tool.dat = 0;
  f->tool.c = 'A';
}

int       ft_get_format(char c)
{
  char    format[14] = "sSpdDioOuUxXcC";
  int     i;

  i = 0;
  while(format[i] != '\0')
  {
    if (format[i] == c)
      return (1);
    i++;
  }
  return (0);
}

int     ft_getval(char **str, t_pf *f, va_list pa)
{
  int     i;

  f->tool.nb = ft_strnew(0);
  i = 0;
  while(**str)
  {
    if (**str == '.')
      f->tool.dat = 1;
    else if (**str == '-')
      f->tool.minus = 1;
    else if (ft_isdigit(**str))
    {
      f->tool.nb[i] = **str;
      f->tool.x = ft_atoi(f->tool.nb);
      i++;
    }
    else if (ft_get_format(**str))
    {
      f->tool.c = **str;
      ft_chose_format(f, pa);
      return (0);
    }
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
  return (0);
}

int main(void) {
  ft_printf("hola %10s loco %i", "mundo", 5);
  return 0;
}
