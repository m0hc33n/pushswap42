#include "../inc/tools.h"

static bool	fetch_value(char *arg, int *value)
{
	int			sign;
	long		res;

	res = 0;
	sign = 1;
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
	if (*arg || res > INT32_MAX || res < INT32_MIN)
		return (false);
	*value = res;
	return (true);
}

bool	arg_validator(int ac, char **av, t_stack **stack)
{
	t_stack	*link;
	int		data;

	if (ac == 1)
		return (NULL);
	while (*(++av))
	{
		if (!**av || !fetch_value(*av, &data))
			return (free_links(stack), false);
		link = create_link(stack, data);
		if (!link)
			return (free_links(stack), false);
	}
	return (true);
}
