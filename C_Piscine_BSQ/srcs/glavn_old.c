#include "../includes/ft.h"
#include <stdio.h>

int	**masiv_input(t_list *list, char buffer, int fd, int dlina)
{
	int i;
	int j;
	int **m;

	i = 0;
	m = (int **)malloc(sizeof(int*) * list->nn);
	while (i<list->nn)
	{
		m[i] = (int*)malloc(dlina * sizeof(int));
		i++;
	}
	i = 0;
	while (i < list->nn)
	{
		j = 0;
		while (j < dlina)
		{
			if(buffer == list->empty)
				m[i][j] = 1;
			if(buffer == list->obstacle)
				m[i][j] = 0;
			read(fd, &buffer, 1);
			if (buffer != list->empty && buffer != list->obstacle && j != (dlina - 1))
			{
				write(1, "ERROR3\n", 7);
				return (NULL);
			}
			j++;
		}
		if (buffer != '\n')
		{
			write(1, "ERROR4\n", 7);
			return (NULL);
		}
		read(fd, &buffer, 1);
		i++;
	}
	list->l = j - 1;
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
		while (j <= list->l)
		{
			if(i > 0 && j != 0 && m[i][j] != 0)
			{
				(list_2->I) = i - 1;
				list_2->J = j -1;
				m[i][j] = min(m[list_2->I][list_2->J], m[i][list_2->J], m[list_2->I][j]);
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
		while (j <= list->l)
		{
			if(max < m[i][j])
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

void	write_map(int fd, t_list_2 *list_2, t_list *list)
{
	int	i;
	int s;
	int j;
	char    buffer;

	read(fd, &buffer, 1);
	while (buffer != '\n')
		read(fd, &buffer, 1);
	s = 2;
	i = 0;
	while (i < list->nn)
	{
		j = 0;
		if(s != 2)
			write (1, &buffer, 1);
		while(j <= list->l)
		{
			s = read(fd, &buffer, 1);
			if(i >= list_2->Id && i <= list_2->I && j >= list_2->Jd && j <= list_2->J)
				write (1, &list->full, 1);
			else
				write (1, &buffer, 1);
			j++;
		}
		s = read(fd, &buffer, 1);
		i++;
	}
}

int	error(int dlina_number, char *number, int fd)
{
	int	i;

	i = 0;
	while (i < (dlina_number-3))
	{
		read(fd, &number[i], 1);
		if (number[i] < '0' || number[i] > '9')
		{
			write (2, "ERROR_1\n", 7);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	error2(t_list *list)
{
	if (list->empty == list->obstacle || list->obstacle == list->full || list->empty == list->full)
	{
		write (2, "ERROR_2\n", 7);
		return (-1);
	}
	return (0);
}

int	glavn(char *argv, int dlina_number, int dlina)
{
	char		buffer;
	int			**m;
	int			i;
	int			j;
	char		*number;
	int 		fd;
	t_list		*list;
	t_list_2	*list_2;
    
	list = (t_list *)malloc(sizeof(t_list));
	list_2 = (t_list_2 *)malloc(sizeof(t_list_2));
	i = 0;
	j = 0;
	fd = open(argv, O_RDWR);
	number = (char *)malloc(sizeof(char) * (dlina_number - 2));
      /*while (i < (dlina_number-3))
      {
          read(fd, &number[i], 1);
          if (number[i] < '0' || number[i] > '9')
          {
              write (2, "ERROR\n", 7);
              return (0);
          }
          i++;
      }*/
	if (error(dlina_number, number, fd) == -1)
		return (0);
	i = 0;
	list->nn = ft_atoi(number);
	read(fd, &buffer, 1);
	list->empty = buffer;
	read(fd, &buffer, 1);
	list->obstacle = buffer;
	read(fd, &buffer, 1);
	list->full = buffer;
      /*if (list->empty == list->obstacle || list->obstacle == list->full || list->empty == list->full)
      {
          write (2, "ERROR\n", 7);
          return (0);
      }*/
	if (error2(list) == -1)
		return (0);
	read(fd, &buffer, 1);
	read(fd, &buffer, 1);
	m = masiv_input(list, buffer, fd, dlina);
	if (m == NULL)
		return (0);
	m = calc(list, m, list_2);
	maxx(list, m, list_2);
	close(fd);
	fd = open(argv, O_RDWR);
	write_map(fd, list_2, list);
	return (fd);
}
