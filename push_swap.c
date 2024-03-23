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

void free_split_array(char **split_array)
{
    int i = 0;
    while (split_array[i] != NULL)
    {
        free(split_array[i]);
        i++;
    }
    free(split_array);
}

static long	ft_atol(const char *s)
{
    long	result;
    int		sign;

    result = 0;
    sign = 1;
    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'
        || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (ft_isdigit(*s))
        result = result * 10 + (*s++ - '0');
    return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
    t_stack	*node;
    t_stack	*last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->cheapest = 0;
    node->nbr = n;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
    free_stack(stack);
}

int initialize_stacks(int ac, char **av, t_stack **a)
{
    int i = 1;
    char **split_av;

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
    return (0);
}

int init_stack_a(t_stack **a, char **split_av)
{
    int i = 0;
    while (split_av[i] != NULL)
    {
        long n;
        char *arg = split_av[i];

        if (error_syntax(arg))
        {
            free_split_array(split_av);
            free_errors(a, NULL);
            return -1;
        }
        n = ft_atol(arg);
        if (n > INT_MAX || n < INT_MIN)
        {
            free_split_array(split_av);
            free_errors(a, NULL);
            return -1;
        }
        if (error_duplicate(*a, (int)n))
        {
            free_split_array(split_av);
            free_errors(a, NULL);
            return -1;
        }
        append_node(a, (int)n);
        i++;
    }
    return (0);
}

t_stack	*get_cheapest(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node,
    char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
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
    {
        if (initialize_stacks(ac, av, &a) == -1)
            return (1);
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