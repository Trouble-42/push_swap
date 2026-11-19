/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_atoi.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ajeudy <ajeudy@learner.42.tech>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/11/07 07:51:44 by ajeudy			   #+#	  #+#			  */
/*	 Updated: 2026/11/07 08:17:07 by ajeudy			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	str_digit(const char str)
{
	return (str >= '0' && str <= '9');
}

static int	str_space(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n' || str == '\r'
		|| str == '\t' || str == '\v')
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (!str_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while (nptr[i] != '\0' && str_digit(nptr[i]))
	{
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	r = r * s;
	return (r);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = " +-1234ab567";
	int r;
	r = ft_atoi(str);
	printf("%d", r);
	return(0);
}*/
