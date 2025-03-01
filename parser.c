#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	has_duplicates(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
	Helper function that handles spaces and signs (+ or -) at the beginning of a string
	Skips spaces, processes a sign if present, and returns the sign multiplier (1 or -1)
	Returns 0 if there's no digit after the sign, indicating an error
*/
static int	process_sign_and_space(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))	
		return (0);
	return (sign);
}

int ft_atoi_with_overflow_check(const char *str, int *num)
{
    int     i;
    int     sign;
    long    result;

    i = 0;
    result = 0;
    sign = process_sign_and_space(str, &i);
    if (sign == 0)
        return (0);
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        if ((sign > 0 && result > (long)INT_MAX) ||
            (sign < 0 && result > (long)INT_MAX + 1))
            return (0);
        i++;
    }
    if (str[i] != '\0')
        return (0);
    *num = (int)(result * sign);
    return (1);
}

static int	validate_single_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != ' ' && 
			arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	process_split_args(char **split, t_stack **stack_a)
{
	int	i;
	int	num;

	i = 0;
	while (split[i])
	{
		if (!ft_atoi_with_overflow_check(split[i], &num) || 
			has_duplicates(*stack_a, num))
		{
			free_split(split);
			return (0);
		}
		add_node_back(stack_a, create_new_node(num));
		i++;
	}
	free_split(split);
	return (1);
}

static int	parse_single_arg(char *arg, t_stack **stack_a)
{
	char	**split;

	if (!validate_single_arg(arg))
		return (0);
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	return (process_split_args(split, stack_a));
}

int	parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	num;

	if (argc == 2)
		return (parse_single_arg(argv[1], stack_a));
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_with_overflow_check(argv[i], &num))
			return (0);
		if (has_duplicates(*stack_a, num))
			return (0);
		add_node_back(stack_a, create_new_node(num));
		i++;
	}
	return (1);
}