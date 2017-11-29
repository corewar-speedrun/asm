/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:59:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/19 19:36:45 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	int				type[3];
	int				ditype[3];
	unsigned char	codage;
	int				byte;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_a
{
	char			*f;
	char			*av;
	char			*basename;
	unsigned int	prog_size;
	int				nameflag;
	int				commflag;
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
	struct s_arg	*args;
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
void			add_code_h(unsigned char cod, t_a *s);
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
void			print_usage(char *pname);
void			cs(char *fn);
void			ve(char *fn, char *er);
int				pe(char *s);
int				last(char *s, int i, int j);
int				emplabdef(void);
int				emplabcal(void);
int				lcnd(void);
int				lccd(void);
int				kostil(char *s);

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

t_arg			*arg_init(void);
int				di_arg(char *tmp, t_a *s, t_arg *arg, int w);
int				r_arg(char *tmp, t_arg *arg, int w);
int				d_arg(char *tmp, t_a *s, t_arg *arg, int w);
int				ir_arg(char *tmp, t_a *s, t_arg *arg, int w);
int				rdi_arg(char *tmp, t_a *s, t_arg *arg, int w);
int				rd_arg(char *tmp, t_a *s, t_arg *arg, int w);
int				eval_reg(char *s, t_arg *a, int w);
int				eval_dir(char *s, t_arg *a, int w, t_a *st);
int				eval_ind(char *s, t_arg *a, int w, t_a *st);
void			add_arg(t_a *s, t_arg *add);
void			badder(t_arg *arg, t_a *s, int args, int ls);
void			badder2(t_arg *arg, int ls, int i, t_a *s);
int				vopros(int j, t_pro *t);
int				check(t_a *s);
int				check_name(t_a *s);
int				ch_naco(t_a *s);
int				print_le(int i, t_a *s);
void			scom(t_a *s);
int				check_comm(t_a *s);
int				ch_op(t_a *s);
int				ch_l(t_a *s);
int				grep_comm(t_a *s, int start, int stop, int i);
int				grep_name(t_a *s, int start, int stop, int i);
int				grep_name2(t_a *s, int *start, int *stop, int *i);
int				grep_comm2(t_a *s, int *start, int *stop, int *i);
void			chooser(int add, t_pro *l, t_a *s);
t_l				*lab_def(char *name, t_a *s);
int				check_ext(t_a *s);
char			*ft_strndup(char *src);
void			add_code_h(unsigned char cod, t_a *s);
void			normefucker1(int add, t_pro *t, t_arg *tmp);
void			normefucker2(int add, t_pro *t, t_a *s, t_arg *tmp);
void			normefucker3(int add, t_pro *t, t_a *s, t_arg *tmp);
void			normefucker4(int add, t_pro *t, t_a *s, t_arg *tmp);
int				normefucker5(char *cmp, int *f, int n, t_a *s);
int				extra(char *s, int i);
t_arg			*get_args(t_a *s, int byte);
void			freespl(char **s);
void			freeall(t_a *s);
void			freeop(char **s);
char			*joincasino(char *s1, char *buf);
void			freeoutput(t_a *s);
void			freeargs(t_a *s);
void			freelablist(t_a *s);
void			freelcallist(t_a *s);
void			freeop(char **s);

void			putmagic(t_a *s);
void			putname(t_a *s);
void			putcomment(t_a *s);
void			putident(t_a *s);
void			putsize(t_a *s);

#endif
