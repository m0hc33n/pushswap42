#include "../inc/push_swap.h"
#include <string.h> //
int	**arg_validator(int ac, char **av)
{
	int	**stack;
	int	cursor;

	if (ac == 1)
		return (NULL);
	stack = (int **)malloc(ac * sizeof(int *));
	stack[ac - 1] = NULL;
	cursor = 0;
	while (*(++av))
	{
		stack[cursor] = (int *)malloc(sizeof(int));
		if (!**av || !fetch_value(*av, stack[cursor]))
		{
			free_stack(stack);
			return (NULL);
		}
		cursor++;
	}
	return (stack);
}
