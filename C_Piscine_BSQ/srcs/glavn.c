#include "../includes/ft.h"
char	*error_and_numberinput(int dlina_number, t_list	*list, char	*argv)
{
	int	i;
	char	*number;

	list->fd = open(argv, O_RDWR);
	number = (char *)malloc(sizeof(char) * (dlina_number - 2));
	i = 0;
	while (i < (dlina_number - 3))
	{
		read(list->fd, &number[i], 1);
		if (number[i] < '0' || number[i] > '9')
		{
			write (2, "ERROR_1\n", 8);
			return (NULL);
		}
		i++;
	}
	return (number);
}

int	error2(t_list *list, t_list_2	*list_2, int	**m, char	*number)
{
	if (list->empty == list->obstacle || list->obstacle == list->full 
			|| list->empty == list->full)
	{
		write (2, "ERROR_2\n", 8);
		ft_free(list, list_2, m, number);
		return (-1);
	}
	return (0);
}

void    struct_list_input(char  *number, t_list *list)
{
    char    buffer;

    list->nn = ft_atoi(number);
    read(list->fd, &buffer, 1);
    list->empty = buffer;
    read(list->fd, &buffer, 1);
    list->obstacle = buffer;
    read(list->fd, &buffer, 1);
    list->full = buffer;
}

int	**chact_glavn(int	**m, t_list *list, t_list_2 *list_2, char	*argv)
{
	m = calc(list, m, list_2);
	maxx(list, m, list_2);
	close(list->fd);
	list->fd = open(argv, O_RDWR);
	return (m);
}

int	glavn(char *argv, int dlina_number, t_list *list)
{
	int			**m;
	char		*number;
    t_list_2	*list_2;

	m = NULL;
	list_2 = (t_list_2 *)malloc(sizeof(t_list_2));
    number = error_and_numberinput(dlina_number, list, argv);
	if (number == NULL)
	{
		ft_free(list, list_2, m, number);
		return (-1);
	}
	struct_list_input(number, list);
	if (error2(list, list_2, m, number) == -1)
		return (-1);
	m = masiv_input(list);
	if (m == NULL)
	{
		ft_free(list, list_2, m, number);
		return (-1);
	}
	m = chact_glavn(m, list, list_2, argv);
	write_map(list_2, list);
	ft_free(list, list_2, m, number);
	return (0);
}
