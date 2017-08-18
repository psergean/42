#include "./../includes/fdf.h"

void  ft_exit(t_env *env)
{
  free(env);
  exit(0);
  return ;
}

int   check_input(int ac)
{
  if (ac != 2)
  {
    ft_putstr_fd("usage:./fdf file_map.\n", 2);
    return (0);
  }
  return (1);
}
