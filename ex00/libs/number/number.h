/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:31:42 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 16:31:51 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_H
# define NUMBER_H

int	number_parse(char *str, char **number_str);
int	number_print_in_words(char *number_str, char *dict);

#endif
