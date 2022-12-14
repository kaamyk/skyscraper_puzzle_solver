int	ft_is_in_line(int *tab, int i, int val)
{
	int	j;

	j = 4 * (i / 4);
	while (j)
	{
		if (tab[j] == val)
			return (1);
		if (j % 4 == 3)
			break ;
		j++;
	}
	return (0);
}

int	ft_is_in_col(int *tab, int i, int val)
{
	int	j;

	j = i % 4;
	while (j < 16)
	{
		if (tab[j] == val)
			return (1);
		j = j + 4;
	}
	return (0);
}

void	ft_assigne(int value, int *tmp, int *ctr)
{
	*tmp = value;
	(*ctr)++;
}

int	ft_lin_view_valid(int *tab, int *view, int position)
{
	int	ctr;
	int	ctr_r;
	int	j;
	int	tmp1;
	int	tmp2;

	ctr = 1;
	ctr_r = 1;
	j = (4 * (position / 4));
	tmp1 = tab[j];
	tmp2 = tab[j];
	while (j % 4 <= 3)
	{
		if (tab[j] > tmp1)
			ft_assigne(tab[j], &tmp1, &ctr);
		if (tab[j] < tmp2)
			ft_assigne(tab[j], &tmp2, &ctr_r);
		if (j % 4 == 3)
			break ;
		j++;
	}
	if (ctr != view[8 + (position / 4)] || ctr_r != view[12 + (position / 4)])
		return (0);
	else
		return (1);
}

int	ft_col_view_valid(int *tab, int *view, int position)
{
	int	ctr;
	int	ctr_r;
	int	j;
	int	tmp1;
	int	tmp2;

	ctr = 1;
	ctr_r = 4;
	j = position % 4;
	tmp1 = tab[j];
	tmp2 = tab[j];
	while (j < 12)
	{
		if (tab[j] > tmp1)
			ft_assigne(tab[j], &tmp1, &ctr);
		if (tab[j] < tmp2)
			ft_assigne(tab[j], &tmp2, &ctr_r);
		j = j + 4;
	}
	if (ctr != view[position % 4] && ctr_r != view[4 + position % 4])
		return (0);
	else
		return (1);
}
