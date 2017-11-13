/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/12 14:20:58 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO в место вызова лейбла записывать
//"байт дефайна лейбла - байт начала операции, где он вызван"

int	p_live(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp1, &arg, 0, s))
			return (0);
	}
	else
		return (dir_exp(a));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	arg.codage = 0;
	badder(&arg, s, 1, 4);
	printf("~~~~~~~~~~~live arg |%s|\n", tmp1);
	return (1);
}

int	p_ld(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (tmp2[0][0] != 'r')
	{
		if (!eval_ind(tmp2[0], &arg, 1, s))
			return (0);
	}
	else
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else
		return (reg_exp(tmp2[1]));
	/***************OUTPUT******************/
	arg.codage = arg.codage << 2;
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 2, 4);
	printf("~~~~~~~~~~~ld arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_st(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] != DIRECT_CHAR)
	{
		if (!eval_ind(tmp2[1], &arg, 1, s))
			return (0);
	}
	else
		return (reg_exp(tmp2[0]));
	/***************OUTPUT******************/
	arg.codage = arg.codage << 2;
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	badder(&arg, s, 2, 2);
	printf("~~~~~~~~~~~st arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_add(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (tmp2[2][0] == 'r')
	{
		if (!eval_reg(tmp2[2], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 2);
	printf("~~~~~~~~~~~add arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_sub(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (tmp2[2][0] == 'r')
	{
		if (!eval_reg(tmp2[2], &arg, 0))
			return (0);
	}
	else
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	badder(&arg, s, 3, 2);
	printf("~~~~~~~~~~~sub arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_and(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 4);
	printf("~~~~~~~~~~~and arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_or(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 4);
	printf("~~~~~~~~~~~or arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_xor(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 4);
	printf("~~~~~~~~~~~xor arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_zjmp(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp1, &arg, 0, s))
			return (0);
	}
	else
		return (dir_exp(a));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	printf("~~~~~~~~~~~zjmp arg |%s|\n", tmp1);
	arg.codage = 0;
	badder(&arg, s, 1, 2);
	return (a[0]);
}

int	p_ldi(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 2);
	printf("~~~~~~~~~~~ldi arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_sti(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!eval_reg(tmp2[0], &arg, 0))
		return (reg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (tmp2[2][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[2], &arg, 2, s))
			return (0);
	}
	else if (tmp2[2][0] == 'r')
		if (!eval_reg(tmp2[2], &arg, 2))
			return (0);
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	/***************OUTPUT******************/
	badder(&arg, s, 3, 2);
	printf("~~~~~~~~~~~sti arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_fork(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp1, &arg, 0, s))
			return (0);
	}
	else
		return (dir_exp(a));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	arg.codage = 0;
	badder(&arg, s, 1, 2);
	printf("~~~~~~~~~~~fork arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_lld(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (tmp2[0][0] != 'r')
	{
		if (!eval_ind(tmp2[0], &arg, 1, s))
			return (0);
	}
	else
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else
		return (reg_exp(tmp2[1]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 2, 4);
	printf("~~~~~~~~~~~lld arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_lldi(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	badder(&arg, s, 3, 2);
	printf("~~~~~~~~~~~lldi arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_lfork(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp1, &arg, 0, s))
			return (0);
	}
	else
		return (dir_exp(a));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	printf("~~~~~~~~~~~lfork arg |%s|\n", tmp1);
	arg.codage = 0;
	badder(&arg, s, 1, 2);
	return (a[0]);
}

int	p_aff(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == 'r')
	{
		if (!eval_reg(tmp1, &arg, 0))
			return (0);
	}
	else
		return (reg_exp(a));
	/***************OUTPUT******************/
	arg.codage = arg.codage << 4;
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	printf("~~~~~~~~~~~aff arg |%s|\n", tmp1);
	badder(&arg, s, 1, 2);
	return (1);
}
