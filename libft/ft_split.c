/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:33 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/02/04 18:25:48 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_string(char const *s, char c)
{
	int	count_strings;
	int	boolean;

	boolean = 1;
	count_strings = 0;
	while (*s)
	{
		if (*s != c && boolean)
		{
			boolean = 0;
			count_strings++;
		}
		else if (*s == c)
			boolean = 1;
		s++;
	}
	return (count_strings);
}

static	void	ft_free(char **split, size_t len )
{
	while (len > 0)
	{
		free(split[len - 1]);
		len--;
	}
	free(split);
	return ;
}

static char	*ft_copy(const char *start, size_t len)
{
	char	*string;

	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, start, len + 1);
	return (string);
}

static	void	ft_len_substring(char **result, const char *s, char c)
{
	int				count_len;
	unsigned int	start;
	char			*search_string;
	size_t			size;

	count_len = 0;
	search_string = (char *)s;
	while (*search_string != '\0')
	{
		while (*search_string == c)
			search_string++;
		start = search_string - s;
		while (*search_string && *search_string != c)
			search_string++;
		if (search_string - s > start)
		{
			size = (size_t)(search_string - s - start);
			result[count_len] = ft_copy(s + start, size);
			if (!result[count_len])
				return (ft_free(result, count_len));
		count_len++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_count_string(s, c);
	split = (char **)malloc((len + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_len_substring(split, s, c);
	split[len] = NULL;
	return (split);
}
/*

include "libft.h"

static    int    ft_count_string(char const s, char c)
{
    int    count_strings;
    int    boolean;

    boolean = 1;
    count_strings = 0;
    while (s)
    {
        if (s != c && boolean)
        {
            boolean = 0;
            count_strings++;
        }
        else if (s == c)
            boolean = 1;
        s++;
    }
    return (count_strings);
}

static    void    ft_free(char split, size_t len )
{
    while (len > 0)
    {
        free(split[len - 1]);
        len--;
    }
    free(split);
    return ;
}

static char    ft_copy(const charstart, size_t len)
{
    char    string;

    string = (char)malloc(len + 1);
    if (!string)
        return (NULL);
    ft_strlcpy(string, start, len + 1);
    return (string);
}

static    int    ft_len_substring(char result, const char *s, char c)
{
    int                count_len;
    unsigned int    start;
    char            search_string;
    size_t            size;

    count_len = 0;
    search_string = (char)s;
    while (search_string != '\0')
    {
        while (search_string == c)
            search_string++;
        start = search_string - s;
        while (search_string &&search_string != c)
            search_string++;
        if (search_string - s > start)
        {
            size = (size_t)(search_string - s - start);
            result[count_len] = ft_copy(s + start, size);
            if (!result[count_len])
            {
                ft_free(result, count_len);
                return (0);
            }
            count_len++;
        }
    }
    return (1);
}

char    ft_split(char const *s, char c)
{
    char    split;
    size_t    len;

    if (!s)
        return (NULL);
    len = ft_count_string(s, c);
    split = (char *)malloc((len + 1) sizeof(char *));
    if (!split)
        return (NULL);
    if (!ft_len_substring(split, s, c))
        return (NULL);
    split[len] = NULL;
    return (split);
}
*/
