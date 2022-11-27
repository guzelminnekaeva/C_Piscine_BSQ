#include "../includes/ft.h"
int	ft_dlina_number(int	fd, t_list	*list)//23line
{
	int		dlina_number;
	char	buffer;

	dlina_number = 0;
	read(fd, &buffer, 1);
	while (buffer != '\n')
	{
		read(fd, &buffer, 1);
		dlina_number++;
	}
	if (dlina_number < 4)
	{
		free(list);
		write (2, "ERROR\n", 7);
		return (-1);
	}
	read(fd, &buffer, 1);
	list->dlina = 0;
	while (buffer != '\n')
	{
		read(fd, &buffer, 1);
		list->dlina++;
	}
	return (dlina_number);
}

int	ft_fd(char	*buffer, int	*number)
{
	int	fd;

	fd = open("eee", O_TRUNC, O_RDWR);
	close(fd);
	fd = open("eee", O_RDWR);

	read(0, &(*buffer), 1);
	while (*buffer <= '9' && *buffer >= '0')
	{
		write(fd, &(*buffer), 1);
		*number = *number * 10 + (*buffer - '0');
		read(0, &(*buffer), 1);
	}
	return (fd);
}

void	txt_input(int	fd, int	n, int	number, char	buffer)
{
	while (n < number + 1)
	{
		if (buffer == '\n')
			n++;
		write(fd, &buffer, 1);
		if (n != number + 1)
		read(0, &buffer, 1);
	}
	close(fd);
	fd = open("eee", O_RDWR);
}
