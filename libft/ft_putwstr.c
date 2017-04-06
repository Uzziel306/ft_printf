#include "libft.h"

/*
** The function begins printing from the address specified (wcs) until it
** reaches the terminating null wide character.
** This terminating null wide character is not printed to the standard output.
*/

int		ft_putwstr(wchar_t *wcs)
{
	int		len;
	len = 0;
	while (*wcs)
	{
		ft_putwchar(*wcs);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
