#include <unistd.h>
#include <signal.h>
void    ft_putnbr(int n)
{
        if (n == -2147483648)
                write (1, "-2147483648", 11);
        else
        {
                
                if (n >= 0 && n <= 9)
                {
                        n += '0';
                        write(1, &n, 1);
                }
                else
                {
                        ft_putnbr(n / 10);
                        ft_putnbr(n % 10);
                }
        }
}
void ft_puchar( char i)
{
        write(1, &i, 1);
        
}
void    sgl(int lol)
{
        static int signal;
        static int x;
        
        if (lol == SIGUSR1)
                signal += (1 << (7 - x));
        x++;
        if (x == 8)
        {
                ft_puchar(signal);
                x = 0;
                signal = 0;
        }
        
}
int main (int ac, char **av)
{
    int x;
    x = 0;
    signal(SIGUSR1, sgl);
    signal(SIGUSR2, sgl);
    ft_putnbr(getpid());
     while (1);    
    return(0);
}