#include "filo.h"

int main(int ac, char **av)
{
    t_data data;

    if(ac < 5 || ac > 6)
        write(1, "error\n", 6);
    if(!ft_isntnum(ac, av))
        write(1, "error\n", 6);
    ft_arg(ac, av, &data);
    ft_fill(&data);
    ft_run_pr(&data);
        
}
 

