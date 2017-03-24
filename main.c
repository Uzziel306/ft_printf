#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

double multiSuma(int operandos, ...)
{

    double resultado = 0.0;
    va_list pa;

    va_start(pa, operandos);

    while (operandos--)
      resultado += va_arg(pa, double);
    va_end(pa);
    return resultado;
}

void ft_putstr(char *str)
{
  int i;

  i = 0;
  while(str[i] != '\0')
  {
    write(1, &str[i],1);
    i++;
  }
}

void pprintf(char *formato, ...) {

    char *p;
    va_list pa;

    va_start(pa, formato);

    for (p = formato; *p; p++) {

        if (*p != '?') {
            putchar (*p);
            continue;
        }

        switch (*++p) {
            case 'd':
                printf("(%d)", va_arg(pa, int));
                break;
            case 's':
                printf("(%s)", va_arg(pa, char *));
                break;
            default:
                putchar(*p);
                break;
            }
        }
        va_end(pa);
}

int ft_printf(const char *format, ...)
{
  char *str;
  va_list pa;
  int i;

  i = 0;
  va_start(pa, format);
  while(format[i] != '\0')
  {
    if(format[i] == '%' && format[i + 1] == 's')
    {
      ft_putstr(va_arg(pa, char*));
      i += 2;
    }
    write(1,&format[i],1);
    i++;
  }
  return (0);
}

int main(void)
{
  char a[5] = "mundo";
  // printf("Resultado es %g\n", multiSuma(10, 2.3, 2.1, 2.2));
  // pprintf("Probemos a poner parentesis a una ?s y a un ?d", "cadena", 25);
  // ft_printf("hola %s estoy loco si\n", "mundo");
  //printf("hola %3s loco\n", a);
//printf("%04d\n", 5);
  printf("hola %20.5s loco", "mundo");
  return 0;
}
