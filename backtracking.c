int	ft_in_lin_col(int *tab, int i, int val);
int	ft_lin_view_valid(int *tab, int *view, int position);
int	ft_col_view_valid(int *tab, int *view, int position);
int	ft_lin_r_view_valid(int *tab, int *view, int position);
int	ft_col_r_view_valid(int *tab, int *view, int position);
int	ft_is_valid(int *tab, int *view, int position);

int	ft_pos_non_null(int *tab, int *view, int position)
{
	if (position % 4 == 3 && ft_lin_view_valid(tab, view, position)
		&& ft_lin_r_view_valid(tab, view, position)
		&& ft_is_valid(tab, view, position + 1))
		return (1);
	else if (position / 4 == 3 && ft_col_view_valid(tab, view, position)
		&& ft_col_r_view_valid(tab, view, position)
		&& ft_is_valid(tab, view, position + 1))
		return (1);
	else if (position / 4 < 3 && position % 4 < 3
		&& ft_is_valid(tab, view, position + 1))
		return (1);
	else
		return (0);
}

int	ft_pos_null(int *tab, int *view, int position)
{
	int	k;

	k = 0;
	while (k++ < 4)
	{
		if (!ft_in_lin_col(tab, position, k))
		{
			tab[position] = k;
			if (position / 4 == 3 && ft_col_view_valid(tab, view, position)
				&& ft_col_r_view_valid(tab, view, position)
				&& ft_is_valid(tab, view, position + 1))
				return (1);
			else if (position % 4 == 3 && ft_lin_view_valid(tab, view, position)
				&& ft_lin_r_view_valid(tab, view, position)
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

int	ft_is_valid(int *tab, int *view, int position)
{
	if (position == 16)
		return (1);
	if (tab[position] != 0)
		return (ft_pos_non_null(tab, view, position));
	else
		return (ft_pos_null(tab, view, position));
}
