	char *p;
	char c;
	int i;
	int j;

	j = 0;
	i = 0;
	if (conv == 'c')
	{
		c = va_arg(list, int);
		while (width-- > 1)
		{
			j++;
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd(c, 1);
		return (j);
	}
	if (conv == 's')
	{
		p = ft_strdup(va_arg(list, char *));
		if (width > precision)
			width += precision - 1;
		while (width-- > (int)ft_strlen(p))
		{
			ft_putchar_fd(' ', 1);
			j++;
		}
		if (precision == 0)
			precision = ft_strlen(p);
		while (precision-- > 0 && p[i])
			ft_putchar_fd(p[i++], 1);
		return (j + i);
	}
	if (conv == 'd' || conv == 'i')
	{
		p = ft_itoa(va_arg(list, int));
		if (precision < 0)
			precision = 0;
		if (precision == 0)
		{
			while (width-- > (int )ft_strlen(p))
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
				i++;
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
		}
		else
		{
			while (--width > precision)
			{
				i++;
				ft_putchar_fd(' ', 1);
			}
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p[0] = '0';
				i++;
			}
			while (precision-- > (int )ft_strlen(p))
			{
				ft_putchar_fd('0', 1);
				i++;
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
		}
	}
	if (conv == 'x')
	{
		p = ft_hex(va_arg(list, long long));
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			while (precision-- > (int)ft_strlen(p))
			{
				ft_putchar_fd('0', 1);
				i++;
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
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
				i++;
				ft_putchar_fd(' ', 1);
			}
			while (precision-- > (int)ft_strlen(p))
			{
				ft_putchar_fd('0', 1);
				i++;
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
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
				i++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
		}
		else
		{
			while (precision-- > (int)ft_strlen(p))
			{
				i++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
		}
	}
	return (0);