#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct		s_tools
{
	int				i;
	int				j;
	int				k;
	int				ret;
	int				len;
	int				x;
	int				minus;
	int				dat;
	char			*nb;
  char      *str;
  char      *buff;
  char      c;
}           t_tools;

typedef struct		s_pf
{
  t_tools tool;
}					t_pf;

int      ft_s_dat(t_pf *f, char *str);
int      ft_s(t_pf *f, char *str);
void      ft_i(t_pf *f, int nb);
#endif
