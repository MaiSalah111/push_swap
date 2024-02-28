/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:59 by maiahmed          #+#    #+#             */
/*   Updated: 2024/02/26 18:08:00 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	main(int ac, char **av)
{
    t_stack	*a;
    t_stack	*b;
    char    **split_av = NULL;
    int     i, j;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (0);
    else
    {
        i = 1;
        while (i < ac)
        {
            split_av = split(av[i], ' ');
            j = 0;
            while (split_av[j] != NULL)
            {
                if (init_stack_a(&a, split_av[j]) == ERROR)
                {
                    while (split_av[j] != NULL)
                    {
                        free(split_av[j]);
                        j++;
                    }
                    free(split_av);
                    free_stack(&a);
                    free_stack(&b);
                    return (ERROR);
                }
                free(split_av[j]);
                j++;
            }
            free(split_av);
            i++;
        }
    }
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

// int	main(int ac, char **av)
// {
//     t_stack	*a;
//     t_stack	*b;
//     char    **split_av = NULL;
//     int     i, j;

//     a = NULL;
//     b = NULL;
//     if (ac == 1 || (ac == 2 && !av[1][0]))
//         return (0);
//     else
//     {
//         i = 1;
//         while (i < ac)
//         {
//             split_av = split(av[i], ' ');
//             j = 0;
//             while (split_av[j] != NULL)
//             {
//                 init_stack_a(&a, split_av[j]);
//                 free(split_av[j]);
//                 j++;
//             }
//             free(split_av);
//             i++;
//         }
//     }
//     if (!stack_sorted(a))
//     {
//         if (stack_len(a) == 2)
//             sa(&a, false);
//         else if (stack_len(a) == 3)
//             sort_three(&a);
//         else
//             sort_stacks(&a, &b);
//     }
//     free_stack(&a);
//     free_stack(&b);
//     return (0);
// }


// #include "push_swap.h"

// int	main(int ac, char **av)
// {
//     t_stack	*a;
//     t_stack	*b;
//     char    **split_av = NULL;
//     int     i;

//     a = NULL;
//     b = NULL;
//     if (ac == 1 || (ac == 2 && !av[1][0]))
//         return (0);
//     else if (ac >= 2)
//     {
//         split_av = split(av[1], ' ');
//         av = split_av;
//     }
//     init_stack_a(&a, av + 1);
//     if (!stack_sorted(a))
//     {
//         if (stack_len(a) == 2)
//             sa(&a, false);
//         else if (stack_len(a) == 3)
//             sort_three(&a);
//         else
//             sort_stacks(&a, &b);
//     }
//     free_stack(&a);
//     free_stack(&b);
//     if (split_av != NULL)
// 	{
//         i = 0;
//         while (split_av[i] != NULL)
//         {
//             free(split_av[i]);
//             i++;
//         }
//         free(split_av);
//     }
//     return (0);
// }
