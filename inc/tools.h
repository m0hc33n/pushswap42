#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h> // exit()
# include <stdlib.h>
# include <unistd.h>

# define ERROR "ERROR\n"
# define ERRORLEN 6

# define ZERO 48
# define PLUS 43
# define MINUS 45
# define SPACE 32

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*flink;
	struct s_stack	*blink;
}					t_stack;

bool				arg_validator(int ac, char **av, t_stack **stack);
int					err(void);

// LINKS
t_stack				*create_link(t_stack **stack, int data);
t_stack				*get_last_link(t_stack *stack);
void				free_links(t_stack **stack);
bool				is_sorted(t_stack *stack);
void				shift_up_index(t_stack *stack);
void				shift_down_index(t_stack *stack);

// UTILS
char				**ft_split(char const *s, char c);
void				free_split(char **args);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);

// ACTIONS
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);


#endif