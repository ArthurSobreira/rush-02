/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:19 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 19:20:34 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

int	std_strcmp(char *s1, char *s2);
int	std_strcpy(char *dest, char *src);
int	std_realloc_char(char **p, unsigned int *size);
int	std_strlen(char *str, unsigned int *len);
int	std_putstr(char *str);
int	std_putchar(char c);

#endif
