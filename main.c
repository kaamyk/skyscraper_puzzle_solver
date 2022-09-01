#include <stdio.h>

void	ft_init_tab(int *tab, int *view);
int		ft_args_valid(char *arg);
int		ft_views_valid(char *view);
int		ft_debug(int *view, char *arg);
int		ft_view_is_valid(int *tab, int *view, int i);
int		ft_is_in_col(int *tab, int i, int val);
int		ft_is_in_line(int *tab, int i, int val);
int		ft_is_valid(int *tab, int *view, int position);

void	ft_init_view(char *arg, int *view)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		if (arg[i] >= '1' && arg[i] <= '4')
		{
			view[j] = arg[i] - '0';
			j++;
		}
		i++;
	}
}

void	ft_print_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("%d", tab[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	tab[16];
	int	view[16];
	int	i;

	(void)argc;
	i = 0;
	while (i < 16)
	{
		tab[i] = 0;
		view[i] = 0;
		i++;
	}
	if (argc != 2 || !ft_debug(view, argv[1]))
		return (0);
	ft_init_view(argv[1], view);
	ft_init_tab(tab, view);
	ft_is_valid(tab, view, 0);
	ft_print_tab(tab);
	return (0);
}
