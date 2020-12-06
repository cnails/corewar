/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:00:45 by hcloves           #+#    #+#             */
/*   Updated: 2020/12/05 21:31:47 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	ft_len_trim(char const *s)
{
	size_t	count;

	count = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (0);
	while (*s != '\0')
	{
		s++;
		count++;
	}
	s--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s--;
		count--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char			*trim;
	size_t			len_trim;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	len_trim = ft_len_trim(s);
	if (len_trim == 0 || !(len_trim + 1))
		return (ft_strnew(1));
	trim = (char *)malloc(sizeof(char) * (len_trim + 1));
	if (!trim)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	while (i < len_trim && *s)
	{
		trim[i] = *s;
		i++;
		s++;
	}
	trim[i] = '\0';
	return (trim);
}
