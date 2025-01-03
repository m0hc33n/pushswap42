#include "../inc/tools.h"

static void	index_minus_minus(t_stack *stack)
{
	if (stack && stack->flink->index > 0)
	{
		while (stack->index < stack->flink->index)
		{
			stack->index--;
			stack = stack->flink;
		}
		stack->index--;
	}
}

static void	index_plus_plus(t_stack *stack)
{
	if (stack)
	{
		while (stack->index < stack->flink->index)
		{
			stack->index++;
			stack = stack->flink;
		}
		stack->index++;
	}
}

static void	push(t_stack **push_to, t_stack **pop_from)
{
	t_stack	*new_head;

	if (push_to && pop_from && *pop_from)
	{
		(*pop_from)->blink->flink = (*pop_from)->flink;
		(*pop_from)->flink->blink = (*pop_from)->blink;
		new_head = *pop_from;
		if (!((*pop_from)->index < (*pop_from)->flink->index))
			*pop_from = NULL;
		else
			*pop_from = (*pop_from)->flink;
		index_minus_minus(*pop_from);
		new_head->blink = new_head;
		new_head->flink = new_head;
		if (*push_to)
		{
			index_plus_plus(*push_to);
			new_head->flink = (*push_to);
			new_head->blink = (*push_to)->blink;
			(*push_to)->blink = new_head;
			new_head->blink->flink = new_head;
		}
		*push_to = new_head;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool out)
{
	if (stack_a && stack_b && *stack_b)
	{
		push(stack_a, stack_b);
		if (out)
			write(STDOUT_FILENO, PA, 3);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool out)
{
	if (stack_a && stack_b && *stack_a)
	{
		push(stack_b, stack_a);
		if (out)
			write(STDOUT_FILENO, PB, 3);
	}
}
