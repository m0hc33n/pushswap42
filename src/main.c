#include "../inc/push_swap.h"

/*
	print stack // to remove
*/
// #include <stdio.h>
// void	print_stack(t_stack *stack)
// {
// 	int is_rot = 0;
// 	if (stack)
// 	{
// 		while (!is_rot)
// 		{
// 			printf("\t\t{ data : %10d  , ordred_index : %10d , address : %p ,  
//				flink : %p , blink %p}\n", stack->data, 
// 				stack->ordred_index , stack ,stack->flink, stack->blink);
// 			stack = stack->flink;
// 			if (stack->index == 0)
// 				is_rot = 1;
// 		}
// 	}
// }

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
	if (is_sorted(stack_a))
		return (free_links(&stack_a), 0);
	set_ordred_index(stack_a, stack_a->blink->index + 1);
	if (stack_a->blink->index <= 2)
		sort_three(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	free_links(&stack_a);
	free_links(&stack_b);
	return (0);
}
