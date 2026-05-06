#include "main.h"

static int	check_nb_virgule(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j > 2 || j < 2)
		return (FAILURE);
	return (SUCCESS);
}

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0' || (str[i] == '-' || str[i] == '+'))
		return (FAILURE);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (FAILURE);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] && (str[i] == ' ' || is_space(str[i]) == SUCCESS))
		i++;
	if (str[i] != '\0')
		return (FAILURE);
	return (SUCCESS);
}

static int	check_limits(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (!str)
		return (FAILURE);
	while (str[i] && is_space(str[i]) == SUCCESS)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 255)
			return (FAILURE);
		i++;
	}
	if (nb < 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	parse_str_color(char *str)
{
	if (!str)
		return (FAILURE);
	if (is_digit(str) == FAILURE || check_limits(str) == FAILURE)
		return (print_error(ERR_ELEM_FORM), FAILURE);
	return (SUCCESS);
}

int	parse_color(char *line, int *data)
{
	char	**result;
	int		tab_color[3];
	int		i;

	if (*data != -1)
		return (print_error(ERR_ELEM_DUP), FAILURE); // free si tab alloué
	if (check_nb_virgule(line) == FAILURE)
		return (print_error(ERR_ELEM_FORM), FAILURE);
	result = ft_split(line, ',');
	if (!result)
		return (print_error(ERR_MALLOC), FAILURE);
	if (!result[0] || !result[1] || !result[2])
		return (free_split(result), print_error(ERR_ELEM_FORM), FAILURE);
	i = 0;
	while (i < 3)
	{
		if (parse_str_color(result[i]) == FAILURE)
			return (free_split(result), FAILURE);
		tab_color[i] = ft_atoi(result[i]);
		i++;
	}
	*data = (tab_color[0] << 16 | tab_color[1] << 8 | tab_color[2]);
	return (free_split(result), SUCCESS);
}
