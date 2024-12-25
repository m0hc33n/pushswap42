#include "../inc/tools.h"

static bool	fetch_value(char *arg, int *value)
{
	int			sign;
	long		res;

	res = 0;
	sign = 1;
	while (*arg == SPACE)
		arg++;
	if (*arg == PLUS || *arg == MINUS)
	{
		if (*arg == MINUS)
			sign *= -1;
		arg++;
	}
	while (*arg >= 48 && *arg <= 57)
	{
		res = (*arg - ZERO) + (res * 10);
		arg++;
	}
	res *= sign;
	while (*arg == SPACE)
		arg++;
	if (*arg || res > INT32_MAX || res < INT32_MIN)
		return (false);
	*value = res;
	return (true);
}

static bool	arg_two_check(int ac, char **av, char ***split)
{
	if (ac == 1)
		return (false);
	else if (ac == 2)
	{
		*split = ft_split(av[1], SPACE);
	}
	return (true);
}

bool	arg_validator(int ac, char **av, t_stack **stack)
{
	t_stack	*link;
	int		data;
	char	**split;

	split = NULL;
	if (!arg_two_check(ac, av, &split))
		return (false);
	if (split)
		av = split;
	while (*(++av))
	{
		if (!**av || !fetch_value(*av, &data))
			return (free_split(split), free_links(stack), false);
		link = create_link(stack, data);
		if (!link)
			return (free_split(split), free_links(stack), false);
	}
	free_split(split);
	return (true);
}
