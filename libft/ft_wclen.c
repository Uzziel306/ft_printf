/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:52 by asolis            #+#    #+#             */
/*   Updated: 2017/01/10 19:40:53 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wclen(wchar_t wc)
{
	int		len;

	len = 0;
	if (wc <= 0xFF)
		len = 1;
	else if (wc < 0x0800)
		len = 2;
	else if (wc < 0x010000)
		len = 3;
	else if (wc < 0x110000)
		len = 4;
	return (len);
}
