int	ft_in_lin_col(int *tab, int position, int val)
{
	int	i;
	int	j;
	int	k;

	i = 4 * (position / 4);
	j = position % 4;
	k = 0;
	while (k < 4)
	{
		if (tab[i] == val || tab[j] == val)
			return (1);
		j += 4;
		i++;
		k++;
	}
	return (0);
}

int	ft_lin_view_valid(int *tab, int *view, int position)
{
	int	ctr;
	int	max;
	int	i;

	position = 4 * (position / 4);
	ctr = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (tab[position] > max)
		{
			max = tab[position];
			ctr++;
		}
		position++;
		i++;
	}
	if (ctr != view[8 + ((position - 1) / 4)])
		return (0);
	else
		return (1);
}

int	ft_lin_r_view_valid(int *tab, int *view, int position)
{
	int	ctr_r;
	int	max;
	int	i;

	position = 4 * (position / 4) + 3;
	ctr_r = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (tab[position] > max)
		{
			max = tab[position];
			ctr_r++;
		}
		position--;
		i++;
	}
	if (ctr_r != view[12 + ((position + 1) / 4)])
		return (0);
	else
		return (1);
}

int	ft_col_view_valid(int *tab, int *view, int position)
{
	int	ctr;
	int	max;
	int	i;

	position = position % 4;
	ctr = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (tab[position] > max)
		{
			max = tab[position];
			ctr++;
		}
		position += 4;
		i++;
	}
	if (ctr != view[position % 4])
		return (0);
	else
		return (1);
}

int	ft_col_r_view_valid(int *tab, int *view, int position)
{
	int	ctr_r;
	int	max;
	int	i;

	position = 12 + position % 4;
	ctr_r = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (tab[position] > max)
		{
			max = tab[position];
			ctr_r++;
		}
		position -= 4;
		i++;
	}
	if (ctr_r != view[4 + (position + 4) % 4])
		return (0);
	else
		return (1);
}
