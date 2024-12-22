#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	if (!arg_validator(ac, av))
		return (write(STDOUT_FILENO, ERROR, ERRORLEN), -1);
	
	printf("success\n");
	return 0;
}
