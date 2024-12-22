#include "../inc/tools.h"

int	err(void)
{
	write(STDOUT_FILENO, ERROR, ERRORLEN);
	return (-1);
}
