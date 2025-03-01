#include "push_swap.h"
#include <stdio.h>
void print_sorted_array(t_stack *stack)
{
    ft_putstr_fd("Sorted array: [", 1);
    while (stack)
    {
        char *num_str = ft_itoa(stack->value);
        ft_putstr_fd(num_str, 1);
        free(num_str);
        
        if (stack->next)
            ft_putstr_fd(", ", 1);
            
        stack = stack->next;
    }
    ft_putstr_fd("]\n", 1);
}

void print_stack(t_stack *stack)
{
	// printf("%s: ", msg);
	// if (!stack)
	// {
	// 	printf("(empty)\n");
	// 	return;
	// }
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}