/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/03/30 14:20:22 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int  fd)
{
    static char *text;
    char        *res;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    text = read_and_stash(fd, text);
    return (res);
}


/**
 * my step:
 * 1 - read from file and stash in
 * 2 - excrat the line
 * 3 - update the leftover
 */

char    *read_and_stash(int fd, char *text)
{
    // read() and add the content from the file to text
}

void stash_file_buffer();