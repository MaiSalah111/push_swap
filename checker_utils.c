/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:38:36 by maiahmed          #+#    #+#             */
/*   Updated: 2024/02/20 18:58:15 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_commands(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
		|| !ft_strcmp(line, "ss"))
		handle_swap_commands(line, a, b);
	else if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb"))
		handle_push_commands(line, a, b);
	else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb")
		|| !ft_strcmp(line, "rr") || !ft_strcmp(line, "rra")
			|| !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		handle_rotate_commands(line, a, b);
	return (1);
}

void	handle_swap_commands(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		swap(a);
	else if (!ft_strcmp(line, "sb"))
		swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(a);
		swap(b);
	}
}

void	handle_push_commands(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "pa"))
		push(a, b);
	else if (!ft_strcmp(line, "pb"))
		push(b, a);
}

void	handle_rotate_commands(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
		rotate(a);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		rotate(b);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		rev_rotate(a);
	if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		rev_rotate(b);
}

void	checker_inistack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	current_index(stack);
	if (argc == 2)
		free_stack(args);
}
