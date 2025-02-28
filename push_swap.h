#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Stack operations */
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* Stack utilities */
t_stack	*create_new_node(int value);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	add_node_front(t_stack **stack, t_stack *new_node);
int		get_stack_size(t_stack *stack);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	free_stack(t_stack **stack);
int		is_stack_sorted(t_stack *stack);
void	assign_index(t_stack **stack_a, int stack_size);
void	print_sorted_array(t_stack *stack);

/* Sorting algorithms */
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size);

/* Input processing */
int		parse_arguments(int argc, char **argv, t_stack **stack_a);
int		ft_atoi_with_overflow_check(const char *str, int *num);
void	print_error(void);

/* Utilities */
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

#endif