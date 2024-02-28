/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:36:10 by maiahmed          #+#    #+#             */
/*   Updated: 2024/02/22 21:13:06 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"
#include "libft/libft.h"

static int	count_words(char const *s, char c)
{
    int		count;
    bool	inside_word;

    count = 0;
    while (*s)
    {
        inside_word = false;
        while (*s == c)
            ++s;
        while (*s != c && *s)
        {
            if (!inside_word)
            {
                ++count;
                inside_word = true;
            }
            ++s;
        }
    }
    return (count);
}

static const char	*skip_delimiters(const char *s, char c)
{
    while (*s && *s == c)
    {
        s++;
    }
    return (s);
}

static char	*copystr(const char *s, char c)
{
    size_t	i;
    char	*str;

    i = 0;
    while (s[i] && s[i] != c)
    {
        i++;
    }
    str = (char *)ft_calloc((i + 1), sizeof(char));
    if (!str)
    {
        return (free(str), NULL);
    }
    ft_memcpy(str, s, i);
    return (str);
}

void	ft_undoalloc(char **s, int i)
{
    while (i >= 0)
    {
        free(s[i]);
        i--;
    }
    free(s);
}

char	**split(char const *s, char c)
{
    char			**split;
    int				count;
    int				i;

    i = 0;
    if (!s)
        return (NULL);
    count = count_words(s, c);
    split = (char **)malloc(sizeof(char *) * (count + 1));
    if (!split)
        return (free(split), NULL);
    while (i < count)
    {
        s = skip_delimiters(s, c);
        split[i] = copystr(s, c);
        if (!split[i])
        {
            ft_undoalloc(split, i);
            return (NULL);
        }
        s += ft_strlen(split[i]);
        i++;
    }
    split[i] = (NULL);
    return (split);
}

// void	ft_undoalloc(char **s, int i)
// {
// 	while (i >= 0)
// 	{
// 		free(s[i]);
// 		i--;
// 	}
// 	free(s);
// }

// int	count_words(char *s, char c)
// {
// 	int		count;
// 	bool	inside_word;

// 	count = 0;
// 	while (*s)
// 	{
// 		inside_word = false;
// 		while (*s == c)
// 			++s;
// 		while (*s != c && *s)
// 		{
// 			if (!inside_word)
// 			{
// 				++count;
// 				inside_word = true;
// 			}
// 			++s;
// 		}
// 	}
// 	return (count);
// }

// static char	*get_next_word(char *s, char c)
// {
// 	static int	cursor = 0;
// 	char		*next_word;
// 	int			len;
// 	int			i;

// 	len = 0;
// 	i = 0;
// 	while (s[cursor] == c)
// 		++cursor;
// 	while ((s[cursor + len] != c) && s[cursor + len])
// 		++len;
// 	next_word = malloc((size_t)len * sizeof(char) + 1);
// 	if (!next_word)
// 		return (free(next_word), NULL);
// 	while ((s[cursor] != c) && s[cursor])
// 		next_word[i++] = s[cursor++];
// 	next_word[i] = '\0';
// 	return (next_word);
// }

// char	**split(char *s, char c)
// {
// 	int		words_count;
// 	char	**result_array;
// 	int		i;

// 	i = 0;
// 	words_count = count_words(s, c);
// 	if (!words_count)
// 		exit(1);
// 	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
// 	if (!result_array)
// 		return (free(result_array), NULL);
// 	while (words_count-- >= 0)
// 	{
// 		if (i == 0)
// 		{
// 			result_array[i] = malloc(sizeof(char));
// 			if (!result_array[i])
// 				return (ft_undoalloc(result_array, i), NULL);
// 			result_array[i++][0] = '\0';
// 			continue ;
// 		}
// 		result_array[i++] = get_next_word(s, c);
// 	}
// 	result_array[i] = NULL;
// 	return (result_array);
// }
