#include "../inc/tools.h"

void	free_stack(int	**stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

bool	fetch_value(char *arg, int *value)
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
