#include "../inc/tools.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (!arg_validator(ac, av, &stack_a) || !stack_a)
		return (err());
	
	
}