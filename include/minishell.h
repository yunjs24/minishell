/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:21:14 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/09 05:10:24 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>


// # include "../readline/8.2.1/include/readline/readline.h"
// # include "../readline/8.2.1/include/readline/history.h"
// # include "../readline/8.2.1/include/readline/"

# include "struct.h"
# include "builtin.h"
# include "sig_handler.h"
# include "execution.h"
# include "../lib/libft/libft.h"

t_global	g_info;                                                                                                                                                                                                                                                                                                                                            

#endif