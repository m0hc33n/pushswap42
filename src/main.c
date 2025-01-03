#include "../inc/push_swap.h"

/*
	print stack // to remove
*/
#include <stdio.h>
void	print_stack(t_stack *stack)
{
	int is_rot = 0;
	if (stack)
	{
		while (!is_rot)
		{
			printf("\t\t{ data : %10d  , ordred_index : %10d , address : %p ,  flink : %p , blink %p}\n", stack->data, 
				stack->ordred_index , stack ,stack->flink, stack->blink);
			stack = stack->flink;
			if (stack->index == 0)
				is_rot = 1;
		}
	}
}

/*
	Swap (sa, sb, ss): Swap the first two elements at the top of each stack.
	Push (pa, pb): Push an element from one stack to the other.
	Rotate (ra, rb, rr): Rotate the stack, shifting all elements up by one.
	Reverse Rotate (rra, rrb, rrr): Reverse rotate the stack, shifting all elements down by one.
*/


int main(int ac, char **av)
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
	if (is_sorted(stack_a))
		printf("[well done]");
	else
		printf("err");	
	//print_stack(stack_a); //aaaa
	free_links(&stack_a);
	free_links(&stack_b);
	return (0);
}
