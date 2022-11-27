#include "../includes/ft.h"
void	ft_free(t_list	*list, t_list_2	*list_2, int	**m, char	*number)
{
	write(1, "\n", 1);
	free(list_2);
	if(m != NULL)
	{
		list->i = 0;
		while (list->i < list->nn)
		{
			free(m[list->i]);
			list->i++;
		}
	}
	free(m);
	free(number);
}

int **masiv_malloc(t_list *list)
{
    int    i;
    int    **m;

    i = 0;
    m = (int **)malloc(sizeof(int *) * list->nn);
    while (i < list->nn)
    {
        m[i] = (int *)malloc(list->dlina * sizeof(int));
        i++;
    }
    return (m);
}
