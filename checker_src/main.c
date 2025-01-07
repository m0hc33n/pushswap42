#include "../inc/tools.h"
#include "../inc/checker.h"

static bool	cmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

bool	do_instructions(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	if (cmp(instruction, RA))
		ra(stack_a, false);
	else if (cmp(instruction, RB))
		rb(stack_b, false);
	else if (cmp(instruction, RR))
		rr(stack_a, stack_b, false);
	else if (cmp(instruction, RRA))
		rra(stack_a, false);
	else if (cmp(instruction, RRB))
		rrb(stack_b, false);
	else if (cmp(instruction, RRR))
		rrr(stack_a, stack_b, false);
	else if (cmp(instruction, PA))
		pa(stack_a, stack_b, false);
	else if (cmp(instruction, PB))
		pb(stack_a, stack_b, false);
	else if (cmp(instruction, SA))
		sa(*stack_a, false);
	else if (cmp(instruction, SB))
		sb(*stack_b, false);
	else if (cmp(instruction, SS))
		ss(*stack_a, *stack_b, false);
	else
		return (false);
	return (true);
}

bool	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			free(line);
			break ;
		}
		if (!do_instructions(line, stack_a, stack_b))
			return (free(line), false);
		free(line);
	}
	return (true);
}

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
	if (!checker(&stack_a, &stack_b))
		return (free_links(&stack_a), free_links(&stack_b), err());
	if (is_sorted(stack_a) && !stack_b)
		write(STDOUT_FILENO, OK, 3);
	else
		write(STDERR_FILENO, KO, 3);
	free_links(&stack_a);
	free_links(&stack_b);
}
