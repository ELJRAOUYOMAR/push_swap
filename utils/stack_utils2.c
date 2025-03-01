#include "../push_swap.h"


t_stack	*get_stack_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void assign_index(t_stack **stack_a, int stack_size)
{
	t_stack	*current;
	t_stack	*min;
	int		min_val;
	int		i;

	i = 0;
	while (i < stack_size)
	{
		current = *stack_a;
		min = NULL;
		min_val = INT_MAX;
		while (current)
		{
			if (current->value <= min_val && current->index == -1)
			{
				min_val = current->value;
				min = current;
			}
			current = current->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}