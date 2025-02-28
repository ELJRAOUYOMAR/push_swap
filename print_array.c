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

// void    print_sorted_array(t_stack *stack)
// {
//     t_stack *temp;
//     int     *array;
//     int     size;
//     int     i;

//     size = get_stack_size(stack);
//     array = (int *)malloc(sizeof(int) * size);
//     if (!array)
//         return;
    
//     // Copy values to array
//     temp = stack;
//     i = 0;
//     while (temp)
//     {
//         array[i++] = temp->value;
//         temp = temp->next;
//     }
    
//     // Sort array (simple bubble sort for demonstration)
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = 0; j < size - i - 1; j++)
//         {
//             if (array[j] > array[j + 1])
//             {
//                 int temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//             }
//         }
//     }
    
//     // Print sorted array
//     ft_putstr_fd("Sorted array: [", 1);
//     for (i = 0; i < size; i++)
//     {
//         char *num_str = ft_itoa(array[i]);
//         ft_putstr_fd(num_str, 1);
//         free(num_str);
//         if (i < size - 1)
//             ft_putstr_fd(", ", 1);
//     }
//     ft_putstr_fd("]\n", 1);
    
//     free(array);
// }