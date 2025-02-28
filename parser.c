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

int	ft_atoi_with_overflow_check(const char *str, int *num)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((result > INT_MAX && sign == 1) || (result * sign < INT_MIN))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*num = (int)(result * sign);
	return (1);
}

int	parse_single_arg(char *arg, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**split;
	int		num;

	split = NULL;
	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != ' ' && arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (strlen(arg) + 1));
	if (!split)
		return (0);
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+')
		{
			split[j++] = &arg[i];
			while (arg[i] && arg[i] != ' ')
				i++;
			if (arg[i])
				arg[i++] = '\0';
		}
		else
			i++;
	}
	split[j] = NULL;
	i = 0;
	while (split[i])
	{
		if (!ft_atoi_with_overflow_check(split[i], &num) || has_duplicates(*stack_a, num))
		{
			free(split);
			return (0);
		}
		add_node_back(stack_a, create_new_node(num));
		i++;
	}
	free(split);
	return (1);
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