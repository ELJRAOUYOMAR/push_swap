#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_arguments(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		print_error();
		return (1);
	}
	stack_size = get_stack_size(stack_a);
	assign_index(&stack_a, stack_size);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	
	// Print the sorted array
	print_sorted_array(stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 1);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		if (size <= 100)
			sort_chunks(stack_a, stack_b, 15);
		else
			sort_chunks(stack_a, stack_b, 30);
	}
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->index;
	middle = (*stack_a)->next->index;
	bottom = (*stack_a)->next->next->index;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, 1);
	else if (top > middle && middle > bottom)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, 1);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	i;

	min_pos = 0;
	i = 0;
	while (i < 4)
	{
		if ((*stack_a)->index == 0)
		{
			min_pos = i;
			break ;
		}
		*stack_a = (*stack_a)->next;
		i++;
	}
	while (i-- > 0)
		*stack_a = get_stack_before_bottom(*stack_a);
	if (min_pos == 1)
		sa(stack_a, 1);
	else if (min_pos == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (min_pos == 3)
		rra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	sort_three(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, 1);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}