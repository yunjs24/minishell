/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:21:14 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/02 04:33:10 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include "libft.h"

void	display_prompt();
void	get_input();

/*
signal_handler.c
*/
void	signal_handler(int signo);


#endif