#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // exit()
# include <stdbool.h>
# include <stdint.h>

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
}	t_stack;

bool	arg_validator(int ac, char **av, t_stack **stack);
int		err(void);

// LINKS
t_stack	*create_link(t_stack **stack, int data);
t_stack	*get_last_link(t_stack *stack);
void	free_links(t_stack **stack);
bool	is_sorted(t_stack *stack);

// UTILS
char	**ft_split(char const *s, char c);
void	free_split(char **args);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif