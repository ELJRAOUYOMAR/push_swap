#include "../push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = get_stack_bottom(*stack);
	last->next = new_node;
}

void	add_node_front(t_stack **stack, t_stack *new_node)
{
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	new_node->next = *stack;
	*stack = new_node;
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

