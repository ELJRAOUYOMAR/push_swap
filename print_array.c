#include "push_swap.h"

void	print_sorted_array(t_stack *stack)
{
	ft_putstr_fd("Sorted array: [", 1);
	while (stack)
	{
		// Convert integer to string
		char	num_str[12];
		int		i;
		int		temp;
		int		is_negative;

		is_negative = 0;
		i = 0;
		temp = stack->value;
		
		// Handle negative numbers
		if (temp < 0)
		{
			is_negative = 1;
			temp = -temp;
		}
		
		// Handle case when value is 0
		if (temp == 0)
			num_str[i++] = '0';
			
		// Convert integer to string by extracting digits
		while (temp > 0)
		{
			num_str[i++] = (temp % 10) + '0';
			temp /= 10;
		}
		
		// Add negative sign if needed
		if (is_negative)
			num_str[i++] = '-';
			
		// Print digits in reverse order
		while (i > 0)
			write(1, &num_str[--i], 1);
			
		// Print comma if not the last element
		if (stack->next)
			ft_putstr_fd(", ", 1);
			
		stack = stack->next;
	}
	ft_putstr_fd("]\n", 1);
}