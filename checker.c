/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:49 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:34:16 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(int ac, char **av, t_stack **a)
{
	char	**split_av;
	int		i;

	i = 1;
	while (i < ac)
	{
		split_av = split(av[i], ' ');
		if (prep_stack_a(a, split_av) == -1)
		{
			free_split_array(split_av);
			continue ;
		}
		free_split_array(split_av);
		i++;
	}
}

void	process_commands(t_stack **a, t_stack **b)
{
	char	*next_line;

	next_line = NULL;
	next_line = (get_next_line(0, next_line));
	while (next_line)
	{
		apply_command(a, b, next_line);
		free(next_line);
		next_line = (get_next_line(0, next_line));
	}
	free(next_line);
}

void	print_result(t_stack *a)
{
	int	len;

	len = stack_len(a);
	if (stack_is_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	parse_input(ac, av, &a);
	process_commands(&a, &b);
	print_result(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
