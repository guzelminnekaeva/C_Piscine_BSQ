#include "../includes/ft.h"

int	ft_argc_1(t_list	*list)
{
	char	buffer;
	int	n;
	int		number;
	int	fd;
	int		dlina_number;

	n = 0;
	number = 0;
	fd = ft_fd(&buffer, &number);
	txt_input(fd, n, number, buffer);
	dlina_number = ft_dlina_number(fd, list);
	if (dlina_number == -1)
	{
		free(list);
		return (-1);
	}
	close(fd);
	glavn("eee", dlina_number, list);
	close(fd);
	return (0);
}

int	open_close(int	fd, char	*str)
{
	close(fd);
	fd = open(str, O_RDWR);
	return (fd);
}

int close_r(int	fd, int	r)
{
	close(fd);
	r++;
	return 	(r);
}

int	ft_argc(t_list	*list, int	argc, int	r, char	**argv)
{
	int		fd;
	int		dlina_number;

	while (r < argc)
	{
		fd = open(argv[r], O_RDWR);
		dlina_number = ft_dlina_number(fd, list);
		if (dlina_number == -1)
		{
			free(list);
			return (-1);
		}
		fd = open_close(fd, argv[r]);
		if (glavn(argv[r], dlina_number, list) == -1)
		{
			free(list);
			return (-1);
		}
		r = close_r(fd, r);
	}
	return (0);
}

int	main(int argc, char **argv)//30line
{
	int		r;
	t_list	*list;

	r = 1;
	list = (t_list *)malloc(sizeof(t_list));
	if (argc == 1)
	{
		if(ft_argc_1(list) == -1)
			return (0);
	}
	else
	{
		if (ft_argc(list, argc, r, argv) == -1)
			return (0);
	}
	free(list);
	return (0);
}
