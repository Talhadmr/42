/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemir <tdemir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:45:48 by tdemir            #+#    #+#             */
/*   Updated: 2023/01/11 18:05:20 by tdemir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' && str[len - 2] != 'e' && str[len - 3] != 'b'\
			&& str[len - 4] != '.' )
		return (0);
	return (1);
}
