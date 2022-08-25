int ft_check_views(int *view)
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (view[i] <= 0 || view[i] > 4)
            return (0);
        if ((i >= 0 && i <= 3) || (i >= 8 && i <= 11))
        {
            if ((view[i] + view[i + 4] > 5) || (view[i] + view[i + 4] < 3))
                return (0);
        }
        i++;
    }
    return (1);
}

int ft_debug(char *view)
{
    if (!ft_check_views)
        return (0);
    return (1);
}
