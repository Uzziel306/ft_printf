#include "libft.h"

int			ft_putwstr(wchar_t *wcs)
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
