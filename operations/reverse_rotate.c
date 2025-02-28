#include "../push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = get_stack_bottom(*stack_a);
	before_last = get_stack_before_bottom(*stack_a);
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = get_stack_bottom(*stack_b);
	before_last = get_stack_before_bottom(*stack_b);
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}