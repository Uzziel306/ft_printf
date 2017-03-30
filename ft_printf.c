#include "ft_printf.h"

int       ft_chose_format(t_pf *f, va_list pa)
{
  if (f->t.c == 's' || f->t.c == 'S')
    ft_s(f, va_arg(pa, char*));
  else if (f->t.c == 'c' || f->t.c == 'C')
    ft_c(f, va_arg(pa, int));
  else if (f->t.c == 'i' || f->t.c == 'd')
    ft_i(f, va_arg(pa, int));
  else if (f->t.c == '%')
    f->t.res += ft_putchar('%');

  return (0);
}

void      zero(t_pf *f)
{
  f->t.i = 0;
  f->t.j = 0;
  f->t.k = 0;
  f->t.len = 0;
  f->t.x = 0;
  f->t.y = 0;
  f->t.m = 0;
  f->t.dat = 0;
  f->t.dat_nb = 0;
  f->t.c = ' ';
  f->t.nb = ft_strnew(0);
  f->t.nb2 = ft_strnew(0);
  f->t.fnb = 0;
  f->t.pluss = ft_strnew(0);
}

char      ft_get_format(char c)
{
  char    format[15] = "sSpdDioOuUxXcC%";
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
    f->t.nb[f->t.j] = **str;
    f->t.y = ft_atoi(f->t.nb);
    f->t.j += 1;
    f->t.fnb += 1;
  }
  else if (flag == 2)
  {
    f->t.nb2[f->t.k] = **str;
    f->t.x = ft_atoi(f->t.nb2);
    f->t.k += 1;
    f->t.fnb += 1;
  }
}

int     ft_getval(char **str, t_pf *f, va_list pa)
{
  *str += 1;
  while(**str)
  {
    if (**str == '.')
      f->t.dat = 1;
    else if (**str == '-')
      f->t.m = 1;
    else if (**str == '+')
      f->t.plus = 1;
    else if (**str == '#')
      f->t.ht = 1;
    else if ((**str == '0') && ((*(*str - 1)) == '%' || (*(*str - 1)) == '+'))
      f->t.z = 1;
    else if (ft_isdigit(**str) && f->t.dat != 0)
      ft_get_nb(f, 1, str);
    else if (ft_isdigit(**str) && f->t.dat != 1)
      ft_get_nb(f, 2, str);
    else if ((f->t.c = ft_get_format(**str)))
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
  f->t.res = 0;
  while(*str)
  {
    if (*str == '%')
      ft_getval(&str, f, pa);
    else
      f->t.res += ft_putchar(*str);
    str++;
  }
  va_end(pa);
  return (f->t.res);
}
// gcc ft_printf.c ft_s.c ft_i.c ft_c.c -Ift_printf.h libft/libft.a && ./a.out
// int main(void)
// {
//   printf("%4.6s mundo %2C tengo %d años\n","hola", '!', 20);
//   printf("%3.2d\n", -1);
//   ft_printf("%3.2d\n", -1);
//   printf("@moulitest: %.10d\n", -42);
//   ft_printf("@moulitest: %.10d\n", -42);
//   printf("@moulitest: [%.d] {%.0d}\n", 0, 0);
//   ft_printf("@moulitest: [%.d] {%.0d}\n", 0, 0);
//   printf("%4.3d\n",10 );
//   ft_printf("%4.3d\n",10 );
//   printf("😬\n");
//   ft_printf("😬\n");
//   printf("1)%-10.5d\n", 4242);
//   ft_printf("2)%-10.5d\n", 4242);
//   ft_printf("%4.6s mundo %2C tengo %d años\n","hola", '!', 20);
//   printf("%+4d \n", 10);
//   ft_printf("%+4d \n", 10);
//   return 0;
// }
