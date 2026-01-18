/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:58:56 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/12 16:58:56 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "libft.h"
#include "stack.h"
#include "ft_printf.h"
#include "input_validation.h"

static bool	check_input_characters(const char *word)
{
	int	length;
	int	i;

	length = ft_strlen(word);
	if ((length == 0) || (length == 1 && (word[0] == '-' || word[0] == '+')))
		return (false);
	i = 0;
	if (word[0] == '-' || word[0] == '+')
		i++;
	while (i < length)
	{
		if (!ft_isdigit(word[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_int_limit(const char *word)
{
	int		length;
	int		i;
	bool	is_negative;

	length = ft_strlen(word);
	i = 0;
	is_negative = word[0] == '-';
	if (is_negative || word[0] == '+')
		i++;
	while (word[i] == '0' && i < length - 1)
		i++;
	if (length - i > 10)
		return (false);
	if (length - i == 10)
	{
		if (is_negative)
			return (ft_strncmp(&word[i], "2147483648", 10) <= 0);
		else
			return (ft_strncmp(&word[i], "2147483647", 10) <= 0);
	}
	return (true);
}

static bool	check_unique_values(const t_stack *s, int value)
{
	int	i;

	if (is_empty(s))
		return (true);
	i = 0;
	while (i <= s->top)
	{
		if (s->items[i] == value)
			return (false);
		i++;
	}
	return (true);
}

bool	check_check_check_check(const t_stack *s, const char **new_argv, int j)
{
	if (is_full(s))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	if (!check_input_characters(new_argv[j]))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	if (!check_int_limit(new_argv[j]))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	if (!check_unique_values(s, ft_atoi(new_argv[j])))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}
