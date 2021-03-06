/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_tools
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				jj;
	int				zz;
	int				i;
	int				j;
	int				k;
	int				fnb;
	int				res;
	int				len;
	int				temp;
	int				count;
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
	long int		decimalnumber;
	long int		quotient;
	char			hexadecimalnumber[100];
	char			*pluss;
	char			*tmp;
	char			*nb;
	char			*nb2;
	char			*str;
	char			*buff;
	char			c;
}					t_tools;

typedef struct		s_pf
{
	t_tools			t;
}					t_pf;

int					ft_s_dat(t_pf *f, char *str);
int					ft_p(t_pf *f, va_list ap);
int					ft_s(t_pf *f, va_list ap);
int					ft_s_dat(t_pf *f, char *str);
int					ft_s_x(t_pf *f, char *str, int flag);
int					ft_c(t_pf *f, int c);
int					ft_i(t_pf *f, va_list pa);
int					ft_i_d(t_pf *f, char *str);
int					ft_i_x(t_pf *f, char *str);
int					ft_i_x_complex(t_pf *f, char *str);
int					ft_i_x_complex_1(t_pf *f, char *str);
int					ft_i_x_r(t_pf *f, char *str);
int					ft_x(t_pf *f, va_list pa);
int					ft_u(t_pf *f, va_list pa);
int					ft_o(t_pf *f, va_list pa);
int					resul_hex(t_pf *f);
int					ft_chose_format(t_pf *f, va_list pa);
char				*ft_itoa_basel(unsigned long long int value, int base);
char				*reverse_array(char *s);
void				zero(t_pf *f);
#endif
