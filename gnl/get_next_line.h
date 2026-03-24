/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:15:34 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/18 14:15:34 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
int		in_str(char	*str, char c);
void	*ft_calloc(unsigned int nmemb, size_t size);
int		ft_strlen(const char *s);
char	*concat(char *s1, char *s2);
void	*free_return(void *tofree);

#endif
