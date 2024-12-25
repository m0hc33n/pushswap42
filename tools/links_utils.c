#include "../inc/tools.h"

t_stack	*create_link(t_stack **stack, int data)
{
	t_stack	*link;
	t_stack	*last_link;

	if (stack)
	{
		link = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!link)
			return (NULL);
		link->data = data;
		if (*stack)
		{
			last_link = get_last_link(*stack);
			last_link->flink = link;
			link->index = last_link->index + 1;
			link->flink = *stack;
			link->blink = last_link;
			(*stack)->blink = link;
		}
		else
		{
			link->index = 0;
			link->flink = link;
			link->blink = link;
			*stack = link;
		}
		return (link);
	}
	return (NULL);
}

t_stack	*get_last_link(t_stack *stack)
{
	if (stack)
	{
		while (stack->index < stack->flink->index)
			stack = stack->flink;
		return (stack);
	}
	return (NULL);
}

void	free_links(t_stack **stack)
{
	t_stack	*p;
	t_stack	*head;
	bool	is_rot;

	if (stack && *stack)
	{
		head = *stack;
		if ((*stack)->flink && (*stack)->flink->index > 0)
		{
			*stack = (*stack)->flink;
			is_rot = 0;
			while (!is_rot)
			{
				p = (*stack)->flink;
				free(*stack);
				*stack = NULL;
				*stack = p;
				if ((*stack)->index == 0)
					is_rot = 1;
			}
		}
		free(head);
		head = NULL;
	}
}
