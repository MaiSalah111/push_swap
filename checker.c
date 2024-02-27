/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:20 by maiahmed          #+#    #+#             */
/*   Updated: 2024/02/22 18:49:21 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_stack	*a;
    t_stack	*b;
    char	*next_line;
    char    **split_av = NULL;
    int		len;
    int     i;

    a = NULL;
    b = NULL;
    next_line = NULL;
    if (ac == 1)
        return (1);
    else if (ac == 2) {
        split_av = split(av[1], ' ');
        av = split_av;
    }
    init_stack_a(&a, av + 1);
    len = stack_len(a);
    next_line = (get_next_line(0, next_line));
    while (next_line)
    {
        apply_command(&a, &b, next_line);
        next_line = (get_next_line(0, next_line));
    }
    if (stack_sorted(a) && stack_len(a) == len)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free(a);
    if (split_av != NULL) {
        i = 0;
        while (split_av[i] != NULL) {
            free(split_av[i]);
            i++;
        }
        free(split_av);
    }
    return (0);
}


// #include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	char	*next_line;
// 	int		len;

// 	a = NULL;
// 	b = NULL;
// 	next_line = NULL;
// 	if (ac == 1)
// 		return (1);
// 	else if (ac == 2)
// 		av = split(av[1], ' ');
// 	init_stack_a(&a, av + 1);
// 	len = stack_len(a);
// 	next_line = (get_next_line(0, next_line));
// 	while (next_line)
// 	{
// 		apply_command(&a, &b, next_line);
// 		next_line = (get_next_line(0, next_line));
// 	}
// 	if (stack_sorted(a) && stack_len(a) == len)
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// 	free(a);
// }
