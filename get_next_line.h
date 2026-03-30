/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:49 by fananrak          #+#    #+#             */
/*   Updated: 2026/03/30 14:06:46 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 5
# define BUFFER_SIZE 
#endif

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

char    *get_next_line(int  fd);

#endif