/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:42 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/23 17:07:03 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_input(int ac, char **av, t_stack **a)
{
	char	**split_av;
	int		i;

	i = 1;
	while (i < ac)
	{
		split_av = split(av[i], ' ');
		if (init_stack_a(a, split_av) == -1)
		{
			free_split_array(split_av);
			continue ;
		}
		free_split_array(split_av);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else
		process_input(ac, av, &a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
