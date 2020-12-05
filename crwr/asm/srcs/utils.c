/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			eliminate_spaces(char *split, int *i)
{
	while (split[*i] && (split[*i] == ' ' || split[*i] == '\t'))
	{
		(*i)++;
	}
}

int				validate_number(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (i == 0 && (name[i] == '+' || name[i] == '-'))
		{
			i++;
			continue;
		}
		if (name[i] < '0' || name[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int				length_of_massiv(char **args)
{
	int i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

static char		*strjoin_our(char *s1, char *s2)
{
	char	*ans;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ans = ft_strnew(len);
	if (!ans)
		return (NULL);
	ans = ft_strcat(ans, s1);
	ans = ft_strcat(ans, s2);
	ans[len] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ans);
}

int				count_number_lines(t_data *data, int num)
{
	char	*string;
	char	*label;
	int		i;
	char	*str;

	str = NULL;
	label = ft_strdup(" ");
	while (get_next_line(data->read_fd, &string) && (num = num + 1) > -10)
	{
		i = 0;
		if (ft_strchr(string, LABEL_CHAR))
		{
			if ((str = parsing_of_label(string, &i)) != NULL)
			{
				i = 0;
				label = strjoin_our(label, parsing_of_label(string, &i));
				ft_strdel(&str);
			}
		}
		ft_strdel(&string);
	}
	data->all_labels = ft_strdup(label);
	ft_strdel(&string);
	ft_strdel(&label);
	return (num);
}
