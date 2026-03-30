/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/03/30 21:43:04 by fanantenana      ###   ########.fr       */
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

char    *read_and_stash(int fd, char *stash)
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
char    *extract_line(char *stash)
{
    char    *line;
    ssize_t i;
    
    if (!stash)
        return (NULL); 
    while (stash[i] && stash[i] != '\n') 
        i++;
    if (stash[i] == '\n')
        line = ft_substr(stash, 0, i + 1);
    else
        line = ft_substr(stash, 0, i);
    return (line);
}
char    *update_leftover(char * leftover)
{    
    // to be implemented
}