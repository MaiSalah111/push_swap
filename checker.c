/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:20 by maiahmed          #+#    #+#             */
/*   Updated: 2024/02/20 17:00:04 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	*line;

	if (argc < 2)
		return (0);
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	*a = (NULL);
	*b = (NULL);
	ft_check_args(argc, argv);
	checker_inistack(a, argc, argv);
	while ((get_next_line(0, line)) > 0)
	{
		if (!apply_commands(line, a, b))
		{
			ft_error("Error\n");
			free(line);
			return (-1);
		}
		free(line);
	}
	print_checker_res(a, b);
	free(a);
	free(b);
}
