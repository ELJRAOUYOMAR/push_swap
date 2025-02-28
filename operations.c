#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = get_stack_bottom(*stack_a);
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = get_stack_bottom(*stack_b);
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

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