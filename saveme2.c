	char *p;
	int i;
	int j;

	i = 0;
	j = 0;
	if (conv == 'd' || conv == 'i')
	{
		p = ft_itoa(va_arg(list, int));
		if (precision < 0)
			precision = 0;
		if (precision == 0)
		{
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p[0] = '0';
				width--;
			}
			while (width-- > (int )ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);	
			}
			ft_putstr_fd(p, 1);
			return (j + 1);
		}
		else
		{
			while (--width > precision)
			{
				ft_putchar_fd(' ', 1);
				j++;
			}
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				j++;
				p[0] = '0';
			}
			while (precision-- > (int )ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p) - 1);
		}
	}
	if (conv == 'x')
	{
		p = ft_hex(va_arg(list, long long));
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--width > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
	}
	if (conv == 'X')
	{
		p = ft_upper(ft_hex(va_arg(list, long long)));
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--width > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
	}
	if (conv == 'u')
	{
		p = ft_itoa(va_arg(list, unsigned int));
		if (precision < 0)
			precision = 0;
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j  + ft_strlen(p));
		}
		else
		{
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
	}
	return (0);