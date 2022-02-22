#include "signal.h"
#include <unistd.h>
int	ft_atoi(const char *str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (str[x] && (str[x] >= '0' && str[x] <= '9'))
	{
		y = y * 10 + str[x] - '0';
		x++;
	}
	return (y);
}
void client(int srv_pid, char str)
{
  int i;
  int x;
  int y;

  y = 0;
  i = 0;
  x = 7;
  while (x >= 0)
  {
    y = (str >> x) & 1;
    if (y == 1)
      kill(srv_pid, SIGUSR1);
    else
      kill(srv_pid, SIGUSR2);
    x--;
  }
}
int main (int ac, char **av )
{
  int j = 0;
  int i;
  int srv_pid;
  i = 0;

  srv_pid = ft_atoi(av[1]);
  if (ac == 3)
  {
    while (av[2][i])
    {
      client(srv_pid, av[2][i]);
      i++;
    }
  }
}