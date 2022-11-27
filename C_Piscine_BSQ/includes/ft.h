/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:12:32 by naqua             #+#    #+#             */
/*   Updated: 2021/09/08 23:16:12 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		min(int dia, int left, int right);
int		ft_atoi(char *str);

typedef struct s_list
{
	char	empty;
	char	obstacle;
	char	full;
	int		nn;
    int     dlina;
	int		i;
	int		j;
	int		fd;
}	t_list;

typedef struct s_list2
{
    int I;
    int J;
    int Id;
    int Jd;
	int	s;
}   t_list_2;

int 	glavn(char *argv, int dlina_number, t_list *list);
int	ft_dlina_number(int	fd, t_list	*list);
int	ft_fd(char	*buffer, int	*number);
void	txt_input(int	fd, int	n, int	number, char	buffer);
int	ft_argc_1(t_list	*list);
int	open_close(int	fd, char	*str);
int close_r(int	fd, int	r);
int	ft_argc(t_list	*list, int	argc, int	r, char	**argv);
int	main(int argc, char **argv);
void	ft_free(t_list	*list, t_list_2	*list_2, int	**m, char	*number);
int **masiv_malloc(t_list *list);
int	**zikl_masiv_input(t_list	*list, char	buffer, int	**m);
int	**masiv_input(t_list *list);
int	**calc(t_list *list, int **m, t_list_2 *list_2);
void	maxx(t_list *list, int **m, t_list_2 *list_2);
void	write_map(t_list_2 *list_2, t_list *list);
char	*error_and_numberinput(int dlina_number, t_list	*list, char	*argv);
int	error2(t_list *list, t_list_2	*list_2, int	**m, char	*number);
void    struct_list_input(char  *number, t_list *list);
int	**chact_glavn(int	**m, t_list *list, t_list_2 *list_2, char	*argv);
int	glavn(char *argv, int dlina_number, t_list *list);

#endif
