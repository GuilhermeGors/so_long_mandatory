/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:43:16 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:26:13 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_putstr_fd_int(const char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (0);
}
