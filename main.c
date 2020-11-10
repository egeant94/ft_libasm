/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:47:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/05 16:35:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *s);

#define STRLEN(x)			printf("real[%ld] mine[%ld]\n", strlen(x), ft_strlen(x));
#define STRCPY(x1, x2, y)	printf("real[%s] mine[%s]\n", strcpy(x1, y), ft_strcpy(x2, y));
#define	STRCMP(x1, x2)		printf("real[%d] mine[%d]\n", strcmp(x1, x2), ft_strcmp(x1, x2));
#define READ(x, y1, y2, z)	printf("real[%ld]", read(x, y1, z)); printf("[%s][%d][%s]", y1, errno, strerror(errno));errno = 0; printf(" mine[%ld]", ft_read(x, y2, z)); printf("[%s][%d][%s]\n", y2, errno, strerror(errno));
#define WRITE(x, y, z)		write(x, y, z); printf("[%d][%s]\n", errno, strerror(errno)); ft_write(x, y, z); printf("[%d][%s]\n", errno, strerror(errno));
#define STRDUP(x)			tmp = strdup(x); printf("real[%s] ", tmp); free(tmp); tmp = ft_strdup(x); printf("mine[%s]\n", tmp); free(tmp);

int		main(void)
{
	char	tmp1[1000];
	char	tmp2[1000];
	char	*tmp;

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

	printf("\n*** read ***\n");
	errno = 0;
	tmp1[5] = 0;
	tmp2[5] = 0;
	READ(0, tmp1, tmp2, 5);
	errno = 0;
	tmp1[4] = 0;
	tmp2[4] = 0;
	READ(0, tmp1, tmp2, 4);
	errno = 0;
	tmp1[0] = 0;
	tmp2[0] = 0;
	READ(0, tmp1, tmp2, 4);
	errno = 0;
	READ(456564654, tmp1, tmp2, 3);

	printf("\n*** write ***\n");
	errno = 0;
	WRITE(1, "test hello", 9);
	WRITE(9324, "test hello", 9);

	printf("\n*** strdup ***\n");
	STRDUP("bruh");
	STRDUP("");
	STRDUP("this string is supposed to be long because I want to do limit testing");
	STRDUP("testing \0 with a manually implemented and text after");
}