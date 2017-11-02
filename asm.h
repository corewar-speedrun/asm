/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:14:18 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/02 14:14:31 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/31 15:19:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>//////////////////////////////////////////////////////////

# define LEAK system("leaks asm");

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct	s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_l
{
	char		*name;
	//add smth else
	struct s_l	*next;
}				t_l;

typedef struct	s_a
{
	char			*f;
	char			*av;
	char			*basename;
	unsigned int	prog_size;
	char			prog_name[PROG_NAME_LENGTH + 1];
	char			*prog_name_tmp;
	char			comment[COMMENT_LENGTH + 1];
	char			*comment_tmp;
	int				curr_line;
	int				i;
	unsigned char	*output;
	int				total_bytes;
	char			**op;
}				t_a;

union			u_onebyte
{
	unsigned char	bit[4];
	unsigned int	magic;
};

int				validate(t_a *s);

#endif
