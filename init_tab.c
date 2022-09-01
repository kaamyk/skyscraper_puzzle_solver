void	ft_set_col(int *tab, int i, int order)
{
	int	ctr;

	ctr = 1;
	if (order > 0)
	{
		while (i < 16)
		{
			tab[i] = ctr;
			ctr++;
			i = i + 4;
		}
	}
	if (order < 0)
	{
		while (i >= 0)
		{
			tab[i] = ctr;
			ctr++;
			i = i - 4;
		}
	}
}

void	ft_set_lin(int *tab, int i, int order)
{
	int	j;

	if (order > 0)
	{
		j = 1;
		while (j <= 4)
		{
			tab[i] = j;
			i++;
			j++;
		}
	}
	if (order < 0)
	{
		j = 4;
		while (j > 0)
		{
			tab[i] = 4 - j;
			i--;
			j--;
		}
	}
}

void	ft_read_col_views(int *tab, int *view, int i, int j)
{
	if (i % 4 == 0 && j / 4 == 0)
	{
		if (view[j] == 1)
			tab[i] = 4;
		else if (view[j] == 4)
			ft_set_col(tab, i, 1);
	}
	else if (i % 4 == 3 && j / 4 == 1)
	{
		if (view[j] == 1)
			tab[i] = 4;
		else if (view[j] == 4)
			ft_set_col(tab, i, -1);
	}
}

void	ft_read_lin_views(int *tab, int *view, int i, int j)
{
	if (i % 4 == 0 && j / 4 == 2)
	{
		if (view[j] == 1)
			tab[i] = 4;
		else if (view[j] == 4)
			ft_set_lin(tab, i, 1);
	}
	else if (i % 4 == 3 && j / 4 == 3 && view[j] == 1)
	{
		if (view[j] == 1)
			tab[i] = 4;
		else if (view[j] == 4)
			ft_set_lin(tab, i, -1);
	}
}

void	ft_init_tab(int *tab, int *view)
{
	int	i;
	int	j;

	i = 0;
	while (i < 16)
	{
		if (!tab[i])
		{
			j = 0;
			while (j < 16)
			{
				if (j / 8 == 0 && i % 4 == j % 4)
					ft_read_col_views(tab, view, i, j);
				else if (j / 8 == 1 && i / 4 == j % 4)
					ft_read_lin_views(tab, view, i, j);
				j++;
			}
			i++;
		}
		else
			i++;
	}
}
