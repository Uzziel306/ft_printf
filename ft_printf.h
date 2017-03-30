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
	int				fnb;
	int				res;
	int				len;
	int				x;
	int				y;
	int				m;
	int				s;
	int				plus;
	int				dat;
	int				z;
	int				dat_nb;
	int				ht;
	int				percent;
	char			*pluss;
	char			*tmp;
	char			*nb;
	char			*nb2;
  char      *str;
  char      *buff;
  char      c;
}           t_tools;

typedef struct		s_pf
{
  t_tools t;
}					t_pf;

int      ft_s_dat(t_pf *f, char *str);
int      ft_s(t_pf *f, char *str);
int    	 ft_c(t_pf *f, int c);
int	     ft_i(t_pf *f, int nb);
void     zero(t_pf *f);
#endif
