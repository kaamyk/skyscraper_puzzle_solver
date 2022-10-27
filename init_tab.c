void	ft_set_col(int *tab, int t_index, int order)
{
	int	ctr;

	ctr = 1;
	if (order > 0)
	{
		while (t_index < 16)
		{
			tab[t_index] = ctr;
			ctr++;
			t_index = t_index + 4;
		}
	}
	if (order < 0)
	{
		while (t_index >= 0)
		{
			tab[t_index] = ctr;
			ctr++;
			t_index = t_index - 4;
		}
	}
}

void	ft_set_lin(int *tab, int t_index, int order)
{
	int	j;

	if (order > 0)
	{
		j = 1;
		while (j <= 4)
		{
			tab[t_index] = j;
			t_index++;
			j++;
		}
	}
	if (order < 0)
	{
		j = 4;
		while (j > 0)
		{
			tab[t_index] = 4 - j;
			t_index--;
			j--;
		}
	}
}

void	ft_read_col_views(int *tab, int *view, int t_index, int v_index)
{
	if (t_index / 4 == 0 && v_index / 4 == 0)
	{
		if (view[v_index] == 1)
			tab[t_index] = 4;
		else if (view[v_index] == 4)
			ft_set_col(tab, t_index, 1);
	}
	else if (t_index / 4 == 3 && v_index / 4 == 1)
	{
		if (view[v_index] == 1)
			tab[t_index] = 4;
		else if (view[v_index] == 4)
			ft_set_col(tab, t_index, -1);
	}
}

void	ft_read_lin_views(int *tab, int *view, int t_index, int v_index)
{
	if (t_index % 4 == 0 && v_index / 4 == 2)
	{
		if (view[v_index] == 1)
			tab[t_index] = 4;
		else if (view[v_index] == 4)
			ft_set_lin(tab, t_index, 1);
	}
	else if (t_index % 4 == 3 && v_index / 4 == 3 && view[v_index] == 1)
	{
		if (view[v_index] == 1)
			tab[t_index] = 4;
		else if (view[v_index] == 4)
			ft_set_lin(tab, t_index, -1);
	}
}

void	ft_init_tab(int *tab, int *view)
{
	int	t_index;
	int	v_index;

	t_index = 0;
	while (t_index < 16)
	{
		if (!tab[t_index])
		{
			v_index = 0;
			while (v_index < 16)
			{
				if (v_index / 8 == 0 && t_index % 4 == v_index % 4)
					ft_read_col_views(tab, view, t_index, v_index);
				else if (v_index / 8 == 1 && t_index / 4 == v_index % 4)
					ft_read_lin_views(tab, view, t_index, v_index);
				v_index++;
			}
			t_index++;
		}
		else
			t_index++;
	}
}
