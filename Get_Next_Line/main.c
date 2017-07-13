#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Libft/libft.h"
#include "stdio.h"

int   main(int ac, char **av)
{
  int fd;
  int count;
  char *line = NULL;

  count = 0;
  //line = (char**)malloc(sizeof(**line));
  fd = open(av[1], O_RDONLY);
//  while(count != 2)
//  {
//    get_next_line(fd, line);
//    count++;
//  }
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
    free(line);
	}
  if (ac == 15)
  {
    ft_putstr("ta mere");
  }
  return (0);
}
