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
#include "libft.h"
#include "stack.h"
#include "ft_printf.h"
#include "input_validation.h"

static bool	check_input_characters(const char *word)
{
	int	length;
	int	i;

	length = ft_strlen(word);
	if ((length == 0) || (length == 1 && word[0] == '-'))
		return (false);
	i = 0;
	if (word[0] == '-')
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
	int	length;

	length = ft_strlen(word);
	if (length > 11)
		return (false);
	if (length == 11 && word[0] == '-')
	{
		if (ft_strncmp(word, "-2147483648", 12) > 0)
			return (false);
	}
	else if (length == 10)
	{
		if (ft_strncmp(word, "2147483647", 11) > 0)
			return (false);
	}
	return (true);
}

static bool	check_unique_values(const Stack *s, int value)
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

bool	check_check_check_check(const Stack *s, const char **new_argv, int j)
{
	if (is_full(s))
	{
		ft_printf("Error\n");
		return (false);
	}
	if (!check_input_characters(new_argv[j]))
	{
		ft_printf("Error\n");
		return (false);
	}
	if (!check_int_limit(new_argv[j]))
	{
		ft_printf("Error\n");
		return (false);
	}
	if (!check_unique_values(s, ft_atoi(new_argv[j])))
	{
		ft_printf("Error\n");
		return (false);
	}
	return (true);
}