/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/07 18:06:59 by dmaznyts         ###   ########.fr       */
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
	//place in compiled code
	struct s_l	*next;
}				t_l;

typedef struct	s_lc
{
	char		*name;
	//place where called from, in compiled code
	struct s_l	*next;
}				t_lc;

typedef struct	s_pro
{
	unsigned char	byte;
	unsigned int	nb;
	struct s_pro	*next;
}				t_pro;

typedef struct	s_o
{
	char			*op;
	unsigned char	opcode;
	unsigned char	codage;
	char			*args;
	struct s_o		*next;
}				t_o;

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
	int				total_bytes;
	char			**op;
	struct s_pro	*output;
	struct s_o		*oplist;
	struct s_l		*lablist;
	struct s_lc		*lcallist;
}				t_a;

union			u_onebyte
{
	unsigned char	bit[4];
	unsigned int	magic;
};

int				validate(t_a *s);
size_t			ft_bytelen(unsigned char *s);
unsigned char	*ft_bytejoin(unsigned char *s1, unsigned char *s2);
void			init2(t_a *s);
void			init(t_a *s);
void			s32(t_a *s);
void			add_op(char *op, t_a *s);
void			add_code(unsigned char cod, t_a *s);
unsigned char	ret_opcode(char *op, t_a *s);

void			p_live(char *a);
void			p_ld(char *a);
void			p_st(char *a);
void			p_add(char *a);
void			p_sub(char *a);
void			p_and(char *a);
void			p_or(char *a);
void			p_xor(char *a);
void			p_zjmp(char *a);
void			p_ldi(char *a);
void			p_sti(char *a);
void			p_fork(char *a);
void			p_lld(char *a);
void			p_lldi(char *a);
void			p_lfork(char *a);
void			p_aff(char *a);

#endif
