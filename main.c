/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:47:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/03 12:03:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

#define STRLEN(x)			printf("real[%ld] mine[%ld]\n", strlen(x), ft_strlen(x));
#define STRCPY(x1, x2, y)	printf("real[%s] mine[%s]\n", strcpy(x1, y), ft_strcpy(x2, y));
#define	STRCMP(x1, x2)		printf("real[%d] mine[%d]\n", strcmp(x1, x2), ft_strcmp(x1, x2));

int		main(void)
{
	char tmp1[1000];
	char tmp2[1000];

	tmp1[999] = '\0';
	tmp2[999] = '\0';

	printf("*** strlen ***\n");
	STRLEN("hello");
	STRLEN("");
	STRLEN("this string is supposed to be long because I want to do limit testing");
	STRLEN("testing \0 with a manually implemented and text after");

	printf("\n*** strcpy ***\n");
	STRCPY(tmp1, tmp2, "hello");
	STRCPY(tmp1, tmp2, "");
	STRCPY(tmp1, tmp2, "this string is supposed to be long because I want to do limit testing");
	STRCPY(tmp1, tmp2, "testing \0 with a manually implemented and text after");

	printf("\n*** strcmp ***\n");
	STRCMP("hello", "hello");
	STRCMP("", "hello");
	STRCMP("hello", "");
	STRCMP("", "");
	STRCMP("hello", "bonjour");
	STRCMP("aa", "az");

}