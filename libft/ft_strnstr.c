/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:27:08 by yubchoi           #+#    #+#             */
/*   Updated: 2021/11/26 14:04:47 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	ret = (char *)haystack;
	while (i < len && ret[i])
	{
		j = 0;
		while (ret[i + j] == needle[j] && needle[j] && (i + j) < len)
			j++;
		if (!needle[j])
			return (&(ret[i]));
		i++;
	}
	return (NULL);
}
