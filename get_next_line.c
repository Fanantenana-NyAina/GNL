/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/03/31 10:45:54 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int  fd)
{
    static char    *leftover;
    char           *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);    
    leftover = read_and_stash(fd, leftover);
    line =  extract_line(leftover);
    leftover = update_leftover(leftover);
    return (line);
}

static char *read_and_stash(int fd, char *stash)
{    
    char    *buffer;
    ssize_t nbytes;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    nbytes = 1;
    while (nbytes > 0)
    {
        nbytes = read(fd, buffer, BUFFER_SIZE);
        buffer[nbytes] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (ft_strchr(stash, '\n'))
            break ;
        
    }
    free(buffer);
    return (stash);
}

static char *extract_line(char *stash)
{
    char    *line;
    ssize_t i;
    
    if (!stash)
        return (NULL); 
    i = 0;
    while (stash[i] && stash[i] != '\n') 
        i++;
    if (stash[i] == '\n')
        line = ft_substr(stash, 0, i + 1);
    else
        line = ft_substr(stash, 0, i);
    return (line);
}

static char *update_leftover(char * stash)
{    
    char    *leftover;
    ssize_t i;
    ssize_t j;
    
    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n') 
        i++;
    leftover = ft_substr(stash, i + 1, ft_strlen(stash) - i);
    return (leftover);
}
