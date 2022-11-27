#include "../includes/ft.h"
int	**zikl_masiv_input(t_list	*list, char	buffer, int	**m)
{
	list->j = 0;
	while (list->j < list->dlina)
	{
		if (buffer == list->empty)
			m[list->i][list->j] = 1;
		if (buffer == list->obstacle)
			m[list->i][list->j] = 0;
		read(list->fd, &buffer, 1);
		if (buffer != list->empty && buffer != list->obstacle
				&& list->j != (list->dlina - 1))
		{
			write(1, "ERROR3\n", 7);
			return (NULL);
		}
		list->j++;
	}
	if (buffer != '\n')
	{
		write(1, "ERROR4\n", 7);
		return (NULL);
	}
	return (m);
}

int	**masiv_input(t_list *list)
{
	int		**m;
	char	buffer;

	read(list->fd, &buffer, 1);
	if (read(list->fd, &buffer, 1) == 0)
	{
		write(2, "ERROR: no map\n", 15);
		return (NULL);
	}
	m = masiv_malloc(list);
	list->i = 0;
	while (list->i < list->nn)
	{
		m = zikl_masiv_input(list, buffer, m);
		if (m == NULL)
			return(NULL);
		read(list->fd, &buffer, 1);
		list->i++;
	}
	return (m);
}

int	**calc(t_list *list, int **m, t_list_2 *list_2)
{
	int			i;
	int			j;

	i = 0;
	while (i < list->nn)
	{
		j = 0;
		while (j <= list->dlina - 1)
		{
			if (i > 0 && j != 0 && m[i][j] != 0)
			{
				(list_2->I) = i - 1;
				list_2->J = j - 1;
				m[i][j] = min(m[list_2->I][list_2->J], \
						m[i][list_2->J], m[list_2->I][j]);
			}
			j++;
		}
		i++;
	}
	return (m);
}

void	maxx(t_list *list, int **m, t_list_2 *list_2)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (i < list->nn)
	{
		j = 0;
		while (j <= list->dlina - 1)
		{
			if (max < m[i][j])
			{
				max = m[i][j];
				list_2->I = i;
				list_2->J = j;
			}
			j++;
		}
		i++;
	}
	list_2->Id = list_2->I + 1 - max;
	list_2->Jd = list_2->J + 1 - max;
}

void	write_map(t_list_2 *list_2, t_list *list)
{
	char	buffer;

	read(list->fd, &buffer, 1);
	while (buffer != '\n')
		read(list->fd, &buffer, 1);
	list_2->s = 2;
	list->i = 0;
	while (list->i < list->nn)
	{
		list->j = 0;
		if (list_2->s != 2)
			write (1, &buffer, 1);
		while (list->j <= (list->dlina - 1))
		{
			list_2->s = read(list->fd, &buffer, 1);
			if (list->i >= list_2->Id && list->i <= list_2->I
					&& list->j >= list_2->Jd && list->j <= list_2->J)
				write (1, &list->full, 1);
			else
				write (1, &buffer, 1);
			(list->j)++;
		}
		list_2->s = read(list->fd, &buffer, 1);
		(list->i)++;
	}
}
