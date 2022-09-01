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
	int	ctr;
	int	j;

	ctr = 1;
	if (order > 0)
	{
		j = 0;
		while (j < 4)
		{
			tab[i] = ctr;
			ctr++;
			i++;
			j++;
		}
	}
	if (order < 0)
	{
		j = 4;
		while (j > 0)
		{
			tab[i] = ctr;
			ctr++;
			i--;
			j--;
		}
	}
}

void	ft_read_col_views(int *tab, int *view, int position, int v_index)
{
	if (position % 4 == 0 && v_index / 4 == 0)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (view[v_index] == 4)
			ft_set_col(tab, position, 1);
	}
	else if (position % 4 == 3 && v_index / 4 == 1)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (view[v_index] == 4)
			ft_set_col(tab, position, -1);
	}
}

void	ft_read_lin_views(int *tab, int *view, int position, int v_index)
{
	if (position % 4 == 0 && v_index / 4 == 2)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (view[v_index] == 4)
			ft_set_lin(tab, position, 1);
	}
	else if (position % 4 == 3 && v_index / 4 == 3 && view[v_index] == 1)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (view[v_index] == 4)
			ft_set_lin(tab, position, -1);
	}
}

void read_views(int *tab, int *view, int position, int v_index)
{
	if (position % 4 == 0)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (view[v_index] == 4)
		{
			if (v_index / 4 == 0)
				ft_set_col(tab, position, 1);
			if (v_index / 4 == 2)
				ft_set_lin(tab, position, 1);
		}
	}
	else if (position % 4 == 3)
	{
		if (view[v_index] == 1)
			tab[position] = 4;
		else if (v_index / 4 == 1)
			ft_set_col(tab, position, -1);
		else if (v_index / 4 == 3 && view[v_index] == 1)
			ft_set_lin(tab, position, -1);
	}
}

void	ft_init_tab(int *tab, int *view)
{
	int	i;
	int	j;

	(void)view;
	i = 0;
	while (i < 16)
	{
		if (!tab[i])
		{
			j = 0;
			while (j < 16)
			{
				/*if (j / 8 == 0 && i % 4 == j % 4)
					ft_read_col_views(tab, view, i, j);
				else if (j / 8 == 1 && i / 4 == j % 4)
					ft_read_lin_views(tab, view, i, j);
				*/
				read_views(tab, view, i, j);
				j++;
			}
		}
		i++;
	}
}
