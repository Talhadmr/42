#include "filo.h"

int main(int ac, char **av) {
  t_data data;

  if (ac < 5 || ac > 6)
    printf("error\n");
  if (!ft_isntnum(ac, av))
    printf("error\n");
  ft_arg(ac, av, &data);
  ft_fill(&data);
  ft_run_pr(&data);
}
