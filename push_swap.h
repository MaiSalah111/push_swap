/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:52 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:31:37 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int					lenstr(const char *str);
char				*find_character(const char *str, int character);
char				*initialize_string(void);
char				*join_strings(char *frst, char *secnd);
char				*read_from_fd(int fd, char *accumulated_str);
char				*skip_to_next_line(char *current_str);
char				*extract_line_from_str(char *str);
char				*get_next_line(int fd, char *line);

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//***Handle errors
int					syntax_err(char *str_n);
int					error_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_err(t_stack **a);
void				ft_putendl_fd(char *s, int fd);

//***Stack initiation
int					prep_stack_a(t_stack **a, char **split_av);
char				**split(char *s, char c);
void				free_split_array(char **split_array);
int					ft_isdigit(int c);

//***Nodes initiation
void				prep_nodes_a(t_stack *a, t_stack *b);
void				prep_nodes_b(t_stack *a, t_stack *b);
void				set_index_median(t_stack *stack);
void				find_cheapest(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);
void				push_prep(t_stack **s, t_stack *n, char c);

//***Stack utils
int					stack_len(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
bool				stack_is_sorted(t_stack *stack);
t_stack				*stack_min(t_stack *stack);
t_stack				*stack_max(t_stack *stack);

//***Commands
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				rr(t_stack **a, t_stack **b, bool print);
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);
void				pa(t_stack **a, t_stack **b, bool print);
void				pb(t_stack **b, t_stack **a, bool print);
void				rev_rotate(t_stack **stack);
void				rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest);
void				rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

//***Algorithm
void				sort_3_nums(t_stack **a);
void				stacks_sorting(t_stack **a, t_stack **b);
void				push_b_to_a(t_stack **a, t_stack **b);
void				move_min_to_top(t_stack **a);
void				push_a_to_b(t_stack **a, t_stack **b);
void				stacks_sorting(t_stack **a, t_stack **b);
void				put_str(char *str, int *len);
void				put_digit(long long int num, int base, int *len);
int					ft_printf(const char *format, ...);

//***Checker
void				checker_error(t_stack **a, t_stack **b, char *command);
int					ft_strcmp(char *str_1, char *str_2);
void				apply_command(t_stack **a, t_stack **b, char *command);
void				handle_swap_commands(char *line, t_stack **a, t_stack **b);
void				handle_push_commands(char *line, t_stack **a, t_stack **b);
void				handle_rotate_commands(char *line, t_stack **a,
						t_stack **b);
void				parse_input(int ac, char **av, t_stack **a);
void				process_commands(t_stack **a, t_stack **b);
void				print_result(t_stack *a);

#endif
