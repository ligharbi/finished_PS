/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:47:34 by ligharbi          #+#    #+#             */
/*   Updated: 2025/06/19 08:47:54 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int		value;
	int		index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int	size;
}	t_stack;

typedef struct s_context
{
	t_stack	*stack;
	int	count_moves;
	int	cost;
	char	**moves;
	int	move_count;
	int	capacity;
}	t_context;

int	count_words(char *s);
char		*first_word(char *str);
char		*move_me(char *s, int i);
char		**sp0_free(int n, char **m, int i);
char		**ft_split(char *s);
int		ft_strcmp(char *s1, char *s2);
void	verif_input(char **s, int c);
bool	dup_int(char **arg, int n);
bool	duplicate(char *s, int n, char **arg);
bool	is_digit(char *str);
bool	check_input(char **s, int c);
int	is_space(char c);
int	is_sign(char c);
long long int	ft_atoi(char *nptr);
char		*ft_strdup(char *s);
t_node	*iniz_stack(char **s, int n);
int	*av_to_tab(int n, char **av);
void	flip(int *p, int *d);
void	selection_sort(int *tab, int n);
int	dicotomic_search(int *tab, int n, int target);
void	assign_indexes(t_node *head, int *tab, int n);
bool	is_sorted(t_node *stack);
t_node	*swap(t_node *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
t_node	*copy_list(t_node *src);
t_stack	*copy_t_stack(t_stack *original);
void	log_move(t_context *ctx, char *move);
int	get_max_bits(t_node *a);
void	process_current_bit(t_context *ctx, int bit, int size);
void	process_bit_passes(t_context *ctx, int bits, int size);
char	**radix_sort(t_context *ctx);
void	init_sort_ctx(t_context *ctx, t_stack *stack);
void	init_ctx(t_context *ctx, t_stack *copy);
int	compute_radix_cost(t_stack *original);
void	sort_with_radix(t_stack *stack);
int	find_min_pos(t_node *a);
void	push_all_to_b(t_context *ctx, int size);
char		**selection_sort_indices(t_context *ctx);
int		init_selection_context(t_context *ctx, t_stack *original);
void	free_selection_context(t_context *ctx);
int		compute_selection_cost(t_stack *original);
int		get_best_move_count(t_stack *stack);
void	ft_putendl_fd(char *s, int fd);
void	print_moves(char **moves, int count);
t_context	init_context(t_stack *stack, int move_count, char **moves_buffer);
int		get_better_sort(t_stack *stack, t_context *ctx);
void	best_sort(t_stack *stack);
void	rest_sort_three(t_stack *s, int i);
void	sort_three_part2(t_stack *s, int i);
bool	already_sorted(t_node *a);
void	sort_three(t_stack *s, int i);
int	stack_len(t_node *a);
int	find_index_pos(t_node *a, int index);
void	rotate_to_top(t_stack *s, int pos, int len);
void	push_smallests_to_b(t_stack *s, int count, int min);
void	sort_four(t_stack *s);
void	sort_five(t_stack *s);
void	free_list(t_node *node);
void	free_stack(t_stack *s, int v);
void	free_moves(char **moves, int count);
void	free_split(char **split);
void	push_swap(int ac, char **av, int *sorted_tab, bool need_free);
int	main(int ac, char **av);

#endif
