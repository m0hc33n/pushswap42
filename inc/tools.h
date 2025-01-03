#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR "Error\n"
# define ERRORLEN 6

# define ZERO 48
# define PLUS 43
# define MINUS 45
# define SPACE 32

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stack
{
	int				data;
	int				index;
	int				ordred_index;
	struct s_stack	*flink;
	struct s_stack	*blink;
}					t_stack;

bool				arg_validator(int ac, char **av, t_stack **stack);
int					err(void);

// LINKS
t_stack				*create_link(t_stack **stack, int data);
void				free_links(t_stack **stack);
bool				is_sorted(t_stack *stack);

// UTILS
char				**ft_split(char const *s, char c);
void				free_split(char **args);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
int					abs(int nbr);

// ACTIONS
void				sa(t_stack *stack_a, bool out);
void				sb(t_stack *stack_b, bool out);
void				ss(t_stack *stack_a, t_stack *stack_b, bool out);
void				pa(t_stack **stack_a, t_stack **stack_b, bool out);
void				pb(t_stack **stack_a, t_stack **stack_b, bool out);
void				ra(t_stack **stack_a, bool out);
void				rb(t_stack **stack_b, bool out);
void				rr(t_stack **stack_a, t_stack **stack_b, bool out);
void				rra(t_stack **stack_a, bool out);
void				rrb(t_stack **stack_b, bool out);
void				rrr(t_stack **stack_a, t_stack **stack_b, bool out);


#endif
