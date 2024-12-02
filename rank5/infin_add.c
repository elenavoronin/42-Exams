// Assignment name  : infin_add
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
// Write a program that takes as a parameter two strings that represent two
// numbers potentially infinit, and displays on stdout the result of the addition
// of these two numbers, followed by a '\n'.
// A negative number will always be prefixed by one and only one -. The only
// characters that can be part of the strings are digits and the sign -.
// Both parameters will always be well formated, and you will always have
// exactly two parameters, no tricks.
// Example:
// $> ./infin_add "879879087" "67548976597" | cat -e
// 68428855684$
// $> ./infin_add "-876435" "987143265" | cat -e
// 986266830$
// $> ./infin_add "-807965" "-34532"
// -842497
// $>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int nr_len(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_strcmp(char *s1, char *s2)
{
	int len1 = nr_len(s1);
    int len2 = nr_len(s2);

    if (len1 != len2) {
        if (len1 > len2) {
            return 1;  // s1 is larger
        } else {
            return -1; // s1 is smaller
        }
    }
	int i = 0;
   	while (s1[i] != '\0') { // Compare digit by digit
        if (s1[i] > s2[i]) {
            return 1;  // s1 is larger
        } else if (s1[i] < s2[i]) {
            return -1; // s1 is smaller
        }
        i++;
    }
    return 0; // Numbers are equal
}

void print_nr(char *res)
{
	int i = 0;
	while (res[i] == '0')
		i++;
	if (res[i] == '\0')
		write(1, "0", 1);
	else 
	{
		while (res[i] != '\0')
		{
			write(1, &res[i], 1);
			i++;
		}
	}
}

void substraction(char *s1, char *s2)
{
	int len1 = nr_len(s1);
	int len2 = nr_len(s2);
	int res_len = (len1 > len2 ? len1 : len2) + 1;
	char *res = malloc(sizeof(char) *(res_len + 1));
	if (!res)
		return ;
	int i  = 0;
	while (i < res_len)
	{
		res[i] = '0';
		i++;
	}
	res[res_len] = '\0'; 
	int borrow = 0;
	i  = 0;
	int nr = 0;
	int digit1 = 0;
	int digit2 = 0;
	while (len1 > 0 || len2 > 0)
	{
		if (len1 > 0)
			digit1 = s1[--len1] - '0';
		else
			digit1 = 0;
		if (len2 > 0)
			digit2 = s2[--len2] - '0';
		else
			digit2 = 0;
		nr = digit1 - digit2 - borrow;
		if (nr < 0) {  // If nrerence is negative, handle borrowing
            nr += 10;
            borrow = 1;  // Set borrow to 1 for the next iteration
        } else 
            borrow = 0;
        res[res_len--] = nr + '0';  // Store the current digit in the result
    }
	print_nr(res);
	free(res);
}

void addition(char *s1, char *s2)
{
	int len1 = nr_len(s1);
	int len2 = nr_len(s2);
	int res_len = (len1 > len2 ? len1 : len2) + 1;
	char *res = malloc(sizeof(char) *(res_len + 1));
	if (!res)
		return ;
	int i  = 0;
	while (i < res_len)
	{
		res[i] = '0';
		i++;
	}
	res[res_len] = '\0'; 
	int remainder = 0;
	int nr = 0;
	int digit1 = 0;
	int digit2 = 0;
	while (len1 > 0 || len2 > 0 || remainder > 0)
	{
		if (len1 > 0)
			digit1 = s1[--len1] - '0';
		else
			digit1 = 0;
		if (len2 > 0)
			digit2 = s2[--len2] - '0';
		else
			digit2 = 0;
		nr = digit1 + digit2 + remainder;
		res[--res_len]  = (nr % 10) + '0';
		remainder = nr / 10;
	}
	print_nr(res);
	free(res);
}


int main(int argc, char **argv)
{
	if (argc != 3)
		return -1;
	
	if (argv[1][0] == '-' && argv[2][0] != '-')
	{
		if (ft_strcmp(argv[1], argv[2]) == 1)
		{
			write(1,"-",1);
			substraction(argv[1] + 1, argv[2]);
		}
		substraction(argv[2], argv[1] + 1);
	}
	if (argv[1][0] != '-' && argv[2][0] == '-')
	{
		if (ft_strcmp(argv[1], argv[2]) == 1)
			substraction(argv[1], argv[2] + 1);
		substraction(argv[2] + 1, argv[1]);
	}
	if (argv[1][0] != '-' && argv[2][0] != '-')
	{
		addition(argv[1], argv[2]);
	}	
	if (argv[1][0] == '-' && argv[2][0] == '-')
	{
		write(1,"-",1);
		addition(argv[1] + 1, argv[2] + 1);
	}
	write(1, "\n", 1);
	return (0);
}
