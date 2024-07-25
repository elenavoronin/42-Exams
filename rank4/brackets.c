#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int validate(char *str)
{
    char open[1000];
    // char    close[1000];

    int i = 0;
    char a = '(';
    char a1 = ')';
    char b = '[';
    char b1 = ']';
    char c = '{';
    char c1 = '}';
    int count = -1;
    while(str[i])
    {
        if (str[i] == a || str[i] == b || str[i] == c)
        {
            count++;
            open[count] = str[i];
        }
        else if (str[i] == a1 || str[i] == c1 || str[i] == b1)
        {
            if (count == -1)
                return(1);
            if ((str[i] == a1 && open[count] != a) ||
            (str[i] == b1 && open[count] != b) ||
                (str[i] == c1 && open[count] != c))
                return (2);
            count--;
        }
        i++;
    }
    if (count == -1)
        return (0);
    return(1);
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int i = 1;
    while (argv[i])
    {
        if (validate(argv[i]) == 0)
            ft_putstr("Ok\n");
        else
            ft_putstr("error\n");
        i++;
    }

    return 0;
}