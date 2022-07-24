/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:11:28 by hel-mefe          #+#    #+#             */
/*   Updated: 2021/12/01 15:12:14 by hel-mefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		in_buffer(char *buffer);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_bzero(char *s, unsigned int start, size_t len);
void	ft_switch_everything_left(char *buffer);
char	*ft_read_file(int fd, char *buffer);
char	*ft_treat_all_cases(int fd, char *buffer);

#endif
