/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:37:29 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/21 20:21:47 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

static int	count_substr(char *str, char separator)
{
	int	count;
	int	j;
	int	in_sub_str;

	count = 0;
	j = 0;
	in_sub_str = 0;
	while (str[j])
	{
		if (!in_sub_str && str[j] != separator)
		{
			in_sub_str = 1;
			count++;
		}
		else if (in_sub_str && str[j] == separator)
			in_sub_str = 0;
		j++;
	}
	return (count);
}

static int	sub_str_len(char *str, char separator)
{
	int	i;

	i = 0;
	while (*str && *str == separator)
		str++;
	while (str[i] && str[i] != separator)
		i++;
	return (i);
}

static char	*ft_strncpy(char *src, int len)
{
	char	*dest;
	int		i;

	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		if (src[i] && i < len)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}

void	*free_matrix(char **mat, int last_index)
{
	int	i;

	i = 0;
	while (i < last_index)
	{
		if (mat[i])
			free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

char	**ft_split(char *src, char separator)
{
	int		string_n;
	char	**split;
	int		i;
	int		j;

	string_n = count_substr(src, separator);
	split = malloc(sizeof(char *) * (string_n + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < string_n)
	{
		while (src[j] && src[j] == separator)
			j++;
		split[i] = ft_strncpy(&src[j], sub_str_len(&src[j], separator));
		if (!split[i])
			return ((char **)free_matrix(split, i));
		j += ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
