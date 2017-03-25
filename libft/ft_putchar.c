/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 20:00:57 by asolis            #+#    #+#             */
/*   Updated: 2017/01/07 20:00:58 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        uctoutf8(const char *dest, wchar_t ch)
{
    unsigned char    *p;

    p = (unsigned char *)dest;
    if (ch < 0x80)
        *p++ = (unsigned char)(ch);
    else if (ch < 0x800)
    {
        *p++ = (unsigned char)((ch >> 6) | 0xC0);
        *p++ = (unsigned char)((ch & 0x3F) | 0x80);
    }
    else if (ch < 0x10000)
    {
        *p++ = (unsigned char)(((ch >> 12)) | 0xE0);
        *p++ =  (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
        *p++ =  (unsigned char)((ch & 0x3F) | 0x80);
    }
    else if (ch < 0x110000)
    {
        *p++ = (unsigned char)(((ch >> 18)) | 0xF0);
        *p++ = (unsigned char)(((ch >> 12) & 0x3F) | 0x80);
        *p++ = (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
        *p++ = (unsigned char)((ch & 0x3F) | 0x80);
    }
    return ((int)p != (int)dest ? 1 : 0);
}

void    ft_putchar(int _c)
{
    wchar_t    c;

    (void)uctoutf8((char *)&c, _c);
    if (_c < 0x80)
        write(1, &c, 1);
    else if (_c < 0x800)
        write(1, &c, 2);
    else if (_c < 0x10000)
        write(1, &c, 3);
    else if (_c < 0x110000)
        write(1, &c, 4);
}
