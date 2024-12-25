#include "../inc/tools.h"

int	err(void)
{
	write(STDOUT_FILENO, ERROR, ERRORLEN);
	return (-1);
}

void	free_split(char **args)
{
	size_t	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			args[i] = NULL;
			i++;
		}
		free(args);
		args = NULL;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((int)count < 0 && (int)size < 0)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
	{
		*(unsigned char *)(b + len) = (unsigned char)c;
	}
	return (b);
}
