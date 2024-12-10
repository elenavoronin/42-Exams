#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int str_len(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

void print_str(char *str)
{
    int i = 0;
    while(str[i] == '0')
        i++;
    if (str[i] == '\0')
		write(1, "0", 1);
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    addition(char *s1, char *s2)
{
    int len1 = str_len(s1);
    int len2 = str_len(s2);
    int res_len = 0;
    if (len1 >= len2)
        res_len = len1 + 1;
    else
        res_len = len2 + 1;
    char *res = malloc(sizeof(char)*(res_len + 1));
    if (!res)
        return ;
    int i = 0;
    while(i < res_len)
    {
        res[i] = '0';
        i++;
    }
    res[i] = '\0';
    i--;
    int reserve = 0;
    int nr = 0;
    int digit_1 = 0;
    int digit_2 = 0;
    len1--;
    len2--;
    while(len1 >= 0 || len2 >= 0 || reserve > 0)
    {
        if (len1 >= 0)
            digit_1 = s1[len1] - '0';
        else
            digit_1 = 0;
        if (len2 >= 0)
            digit_2 = s2[len2] - '0';
        else
            digit_2 = 0;
        nr = digit_1 + digit_2 + reserve;
        res[i] = (nr % 10) + '0';
        reserve = nr / 10;
        i--;
        len1--;
        len2--;
    }
    print_str(res);
	free(res);
}

void substraction(char *s1, char *s2)
{
    int len1 = str_len(s1);
    int len2 = str_len(s2);
    int res_len = 0;
     if (len1 >= len2)
        res_len = len1 + 1;
    else
        res_len = len2 + 1;
    char *res = malloc(sizeof(char)*(res_len + 1));
    if (!res)
        return ;
    int i = 0;
    while(i < res_len)
    {
        res[i] = '0';
        i++;
    }
    res[i] = '\0';
    i--;
    int borrow = 0;
    int nr = 0;
    int digit_1 = 0;
    int digit_2 = 0;
    len1--;
    len2--;
    while(len1 >= 0 || len2 >= 0)
    {
        if (len1 >= 0)
            digit_1 = s1[len1] - '0';
        else
            digit_1 = 0;
        if (len2 >= 0)
            digit_2 = s2[len2] - '0';
        else
            digit_2 = 0;
        nr = digit_1 - digit_2 - borrow;
        if (nr < 0)
        {
            nr += 10;
            borrow = 1;
        }
        res[i] = nr + '0';
        i--;
        len1--;
        len2--;
    }
    print_str(res);
	free(res);
}

int compare(char *s1, char *s2)
{
    int len1 = str_len(s1);
    int len2 = str_len(s2);
    if (len1 > len2)
        return 1;
    else if (len2 > len1)
        return -1;
    
    int i = 0;
    while(i < len1)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s2[i] > s1[i])
            return -1;  
        i++;
    }
    return 0;
}

void check_result(char *s1, char *s2)
{
    if (s1[0] == '-')
    {
        if (compare(s1 + 1, s2) >= 0)
        {
            write(1, "-", 1);
            substraction(s1 + 1, s2);
        }
        else
            substraction(s2, s1 + 1);
    }
    if (s2[0] == '-')
    {
    if (compare(s1, s2 + 1) >= 0)
    {
        
        substraction(s1, s2 + 1);
    }
    else
    {
        write(1, "-", 1);
        substraction(s2 + 1, s1);
    }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    if (argv[1][0] == '0' && argv[2][0] == '0')
    {
        write(1, "0\n", 2);
        return 0;
    }
    if (argv[1][0] == '-' && argv[2][0] == '-')
    {
        write(1, "-", 1);
        addition(argv[1] + 1, argv[2] + 1);
    }
    else if (argv[1][0] != '-' && argv[2][0] != '-')
        addition(argv[1], argv[2]);
    else if (argv[1][0] != '-' && argv[2][0] == '-')
        check_result(argv[1], argv[2]);
    else if (argv[1][0] == '-' && argv[2][0] != '-')
        check_result(argv[1], argv[2]);
    
    write(1, "\n", 1);
    return(0);

}