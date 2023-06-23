#include "filo.h"

int ft_isntnum(int ac , char **av)
{   
    int i;
    int j;


    i = 1;
    while(i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] <= '9' && av[i][j] >= '0'))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	spc_chrc(char c)
{
	if ((c == ' ' || c == '\t' || c == '\r'
			|| c == '\n' || c == '\v' || c == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	neg = 1;
	i = 0;
	num = 0;
	while (spc_chrc(str[i]) == 1)
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + str[i++] - 48;
		if (num * neg < -2147483648)
			return (0);
		if (num * neg > 2147483647)
			return (-1);
	}
	return (neg * num);
}