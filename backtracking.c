int	ft_is_in_line(int *tab, int i, int val);
int	ft_is_in_col(int *tab, int i, int val);
int	ft_view_is_valid(int *tab, int *view, int position);
int	ft_lin_view_valid(int *tab, int *view, int position);
int	ft_col_view_valid(int *tab, int *view, int position);

int	ft_is_valid(int *tab, int *view, int position)
{
	int	k;

	k = 0;
	if (position == 16)
		return (1);
	if (tab[position] != 0)
		return (ft_is_valid(tab, view, position + 1));
	while (k++ < 4)
	{
		if (!ft_is_in_line(tab, position, k) && !ft_is_in_col(tab, position, k))
		{
			tab[position] = k;
			if (position / 4 == 3 && ft_col_view_valid(tab, view, position)
				&& ft_is_valid(tab, view, position + 1))
				return (1);
			else if (position % 4 == 3 && ft_lin_view_valid(tab, view, position)
				&& ft_is_valid(tab, view, position + 1))
				return (1);
			else if (position / 4 < 3 && position % 4 < 3
				&& ft_is_valid(tab, view, position + 1))
				return (1);
		}
	}
	tab[position] = 0;
	return (0);
}
