#include "../inc/tools.h"

static void	set_link_members(t_stack **stack, t_stack *link)
{
	link->ordred_index = 0;
	if (*stack)
	{
		link->index = (*stack)->blink->index + 1;
		link->flink = *stack;
		link->blink = (*stack)->blink;
		(*stack)->blink->flink = link;
		(*stack)->blink = link;
	}
	else
	{
		link->index = 0;
		link->flink = link;
		link->blink = link;
		*stack = link;
	}
}

t_stack	*create_link(t_stack **stack, int data)
{
	t_stack	*link;

	if (stack)
	{
		link = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!link)
			return (NULL);
		link->data = data;
		set_link_members(stack, link);
		return (link);
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
