#include "../inc/tools.h"

static bool	is_sign_valid(char **arg, int *sign)
{
	if (**arg == PLUS || **arg == MINUS)
	{
		if (**arg == MINUS)
			*sign *= -1;
		(*arg)++;
		if (!**arg)
			return (false);
		return (true);
	}
	return (true);
}

static bool	fetch_value(char *arg, int *value)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*arg == SPACE)
		arg++;
	if (!is_sign_valid(&arg, &sign))
		return (false);
	while (*arg >= 48 && *arg <= 57)
	{
		res = (*arg - ZERO) + (res * 10);
		arg++;
	}
	while (*arg == SPACE)
		arg++;
	if (*arg || res > INT32_MAX || res < INT32_MIN)
		return (false);
	res *= sign;
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
		if (!*split)
			return (false);
	}
	return (true);
}

static bool	is_dup(t_stack *stack, int data)
{
	if (stack)
	{
		while (stack->index < stack->flink->index)
		{
			if (stack->data == data)
				return (true);
			stack = stack->flink;
		}
		if (stack->data == data)
			return (true);
	}
	return (false);
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
		if (!**av || !fetch_value(*av, &data) || is_dup(*stack, data))
			return (free_split(split), free_links(stack), false);
		link = create_link(stack, data);
		if (!link)
			return (free_split(split), free_links(stack), false);
	}
	free_split(split);
	return (true);
}
