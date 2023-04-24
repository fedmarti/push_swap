/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:05:52 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/04 18:59:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*r_null(char **str, char **leftover)
{
	if (str)
	{
		if (*str)
			ft_reset(str);
	}
	if (leftover)
	{
		if (*leftover)
			ft_reset(leftover);
	}
	return (NULL);
}

char	*get_leftover(char *str, char *leftover)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n' && str[len + 1])
	{
		leftover = ft_strjoin(&str[len + 1], "");
		if (!leftover)
			return (NULL);
		str[len + 1] = 0;
	}
	else
		leftover = (char *) ft_calloc(1, sizeof(char));
	return (leftover);
}

int	read_more(int fd, char **str, char **leftover)
{
	int		len;
	char	*temp_str;
	char	*temp_2;

	*leftover = get_leftover(*str, *leftover);
	if (!*leftover)
		return (-1);
	if (!**leftover)
		ft_reset(leftover);
	else if (**leftover)
		return (0);
	temp_str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_str)
		return (-1);
	len = read(fd, temp_str, BUFFER_SIZE);
	temp_2 = *str;
	*str = ft_strjoin(temp_2, temp_str);
	free (temp_str);
	free (temp_2);
	return (len);
}

int	loop(int fd, char **str, char **leftover)
{
	int	len;

	while (check(*str))
	{
		len = read_more(fd, str, leftover);
		if (len < 0)
			return (0);
		else if (!*leftover)
		{
			*leftover = get_leftover(*str, *leftover);
			if (!*leftover)
				return (0);
			if (!**leftover)
				ft_reset(leftover);
			else
				break ;
			if (!len)
				break ;
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (r_null(NULL, &leftover));
	str = ft_strjoin(leftover, "");
	if (!str)
		return (r_null(&str, &leftover));
	ft_reset(&leftover);
	if (!loop(fd, &str, &leftover))
		return (r_null(&str, &leftover));
	if (!*str)
		return (r_null(&str, &leftover));
	return (str);
}
/*

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static void	change_color(int i)
{
	if (i % 4 == 0)
		printf("\033[1;31m");
	else if (i % 4 == 1)
		printf("\033[0;34m");
	else if (i % 4 == 2)
		printf("\033[1;33m");
	else
		printf("\033[1;32m");
}
int	main()
{
	int n = 3;
	int i = 2;
	char c[] = "test";
	if (n >= 2)
	{
		int fd = open(c, 'r');
		char *str;
		while (i--)
		{
			str = get_next_line(fd);
			change_color(i);	
			printf("%s", str);
			free(str);
		}	
		close(fd);
	}
}		
*/