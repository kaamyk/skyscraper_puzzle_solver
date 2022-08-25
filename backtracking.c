int ft_is_in_line(int *tab, int i, int val);
int ft_is_in_col(int *tab, int i, int val);
int ft_view_is_valid(int *tab, int *view, int i, int value);
int ft_lin_view_valid(int *tab, int *view, int i, int value);
int ft_col_view_valid(int *tab, int *view, int i, int value);

int ft_line_complete(int *tab, int position)
{
    int lin_comp;
    int i;

    i = 4 * (position / 4);
    lin_comp = 0;
    while (tab[i])
    {
        if (i % 4 == 3)
        {
            lin_comp = 1;
            break;
        }
        i++;
    }
    return (lin_comp);
}

int ft_column_complete(int *tab, int position)
{
    int col_comp;
    int j;

    col_comp = 0;
    j = position % 4;
    while (tab[j])
    {
        if (j >= 12)
        {
            col_comp = 1;
            break;
        }
        j = j + 4;
    }
    return (col_comp);
}

int ft_is_valid(int *tab, int *view, int position)
{
    int k;

    k = 1;
    if (position == 16)
        return (1);
    if (tab[position] != 0)
        return (ft_is_valid(tab, view, position + 1));
    while (k <= 4)
    {
        if (!ft_is_in_line(tab, position, k) && !ft_is_in_col(tab, position, k))
        {
            tab[position] = k;
            if (ft_line_complete(tab, position))
            {
                if (ft_lin_view_valid(tab, view, position, k)) 
                {
                    if (ft_is_valid(tab, view, position + 1))
                        return (1);
                    else
                        break ;
                }
                else
                    break ;
            }
            if (ft_is_valid(tab, view, position + 1))
                return (1);
        }
        k++;
    }
    tab[position] = 0;
    return (0);
}
