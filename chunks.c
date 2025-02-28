#include "push_swap.h"

int	find_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
	int	size;
	int	pushed;
	int	pos;

	size = get_stack_size(*stack_a);
	pushed = 0;
	while (*stack_a && pushed < (end - start))
	{
		if ((*stack_a)->index >= start && (*stack_a)->index < end)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
			if ((*stack_b)->index < (start + end) / 2)
				rb(stack_b, 1);
		}
		else
		{
			pos = find_position(*stack_a, start + pushed);
			if (pos < size / 2)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
	}
}

void	sort_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	size;
	int	chunks;
	int	i;
	int	max;

	size = get_stack_size(*stack_a);
	chunks = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks)
	{
		push_chunk_to_b(stack_a, stack_b, i * chunk_size, 
			(i + 1) * chunk_size > size ? size : (i + 1) * chunk_size);
		i++;
	}
	while (*stack_b)
	{
		max = get_max_index(*stack_b);
		while ((*stack_b)->index != max)
		{
			if (find_position(*stack_b, max) < get_stack_size(*stack_b) / 2)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}