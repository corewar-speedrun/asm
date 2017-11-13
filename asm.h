/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/11 19:34:19 by dmaznyts         ###   ########.fr       */
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

union			u_onebyte
{
	unsigned char	bit[4];
	unsigned int	magic;
};

typedef struct	s_l
{
	char			*name;
	unsigned int	defined;
	struct s_l		*next;
}				t_l;

typedef struct	s_lc
{
	char			*name;
	unsigned int	called_on;
	struct s_lc		*next;
}				t_lc;

typedef struct	s_pro
{
	unsigned char	byte;
	unsigned int	nb;
	struct s_pro	*next;
}				t_pro;

typedef struct	s_arg
{
	int				arg[3];
	int				type[3];	// 1 if label, 0 if num
	int				ditype[3];	// 1 if indirect, 0 if direct
	unsigned char	codage;
}				t_arg;

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
	struct s_l		*lablist;
	struct s_lc		*lcallist;
}				t_a;

int				validate(t_a *s);
size_t			ft_bytelen(unsigned char *s);
unsigned char	*ft_bytejoin(unsigned char *s1, unsigned char *s2);
void			init2(t_a *s);
void			init(t_a *s);
void			s32(t_a *s);
int				add_op(char *op, t_a *s);
int				ass_lab(t_a *s);
void			add_la(char *l, t_a *s);
void			add_lc(char *name, t_a *s);
void			add_code(unsigned char cod, t_a *s);
void			add_4z(t_a *s);
void			add_2z(t_a *s);
void			modify_4b(int add, t_pro *t);
void			modify_2b(int add, t_pro *t);
void			add_4b(int add, t_a *s);
void			add_2b(int a, t_a *s);
unsigned char	ret_opcode(char *op, t_a *s);
int				split_cnt(char **s);
char			*ft_strstrip(char *s, int i, int j);

int				arg_exp(char *a);
int				dir_exp(char *a);
int				reg_exp(char *a);
int				ind_exp(char *a);
int				reg_bad(int got);
int				nc_exp(char a);
int				num_exp(char a);
int				er_stru(void);
int				three_ae(int a);
int				two_ae(int a);
int				ld_er(char *s);

int				p_live(char *a, t_a *s);
int				p_ld(char *a, t_a *s);
int				p_st(char *a, t_a *s);
int				p_add(char *a, t_a *s);
int				p_sub(char *a, t_a *s);
int				p_and(char *a, t_a *s);
int				p_or(char *a, t_a *s);
int				p_xor(char *a, t_a *s);
int				p_zjmp(char *a, t_a *s);
int				p_ldi(char *a, t_a *s);
int				p_sti(char *a, t_a *s);
int				p_fork(char *a, t_a *s);
int				p_lld(char *a, t_a *s);
int				p_lldi(char *a, t_a *s);
int				p_lfork(char *a, t_a *s);
int				p_aff(char *a, t_a *s);

int				eval_reg(char *s, t_arg *a, int w);
int				eval_dir(char *s, t_arg *a, int w, t_a *st);
int				eval_ind(char *s, t_arg *a, int w, t_a *st);
void			badder(t_arg *arg, t_a *s, int args, int ls);

#endif
