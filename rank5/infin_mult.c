// Assignment name  : infin_mult
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
// Write a program that takes as a parameter two strings that represent two
// numbers potentially infinit, and displays on stdout the result of the
// multiplication of these two numbers, followed by a '\n'.
// A negative number will always be prefixed by one and only one -. The only
// characters that can be part of the strings are digits and the sign -.
// Both parameters will always be well formated, and you will always have exactly
// two parameters, no tricks.
// Example:
// $> ./infin_mult "879879087" "67548976597" | cat -e
// 59434931855952726939$
// $> ./infin_mult "-876435" "987143265" | cat -e
// -865166907460275$
// $> ./infin_mult "-807965" "-34532" | cat -e
// 27900647380$
// $> ./infin_mult "-807965" "0"
// 0
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

void multiply(char *s1, char *s2)
{
	char *res = NULL;
	int remainder = 0;
	int nr = 0;
	int len1 = nr_len(s1);
	int len2 = nr_len(s2);
	int res_len = (len1 + len2);
	res = malloc(sizeof(char)*(res_len + 1));
	if (!res)
		return ;
	int i = 0;
	while (i < res_len)
	{
		res[i] = '0';
		i++;
	}
	res[res_len] = '\0';
	int j = len1 - 1;
	while(j >= 0)
	{	
		remainder = 0;
		int res_index = j + len2;
		int k = len2-1;
		while (k >= 0)
		{
			nr = (s1[j] - '0') * (s2[k] - '0') + (res[res_index] - 48) + remainder;
			res[res_index] = (nr % 10) + 48;
			remainder = nr / 10;
			res_index--;
			k--;
		}
		if (remainder > 0)
			res[res_index] = (res[res_index] - 48 + remainder) + 48;
		j--;
	}
	print_nr(res);
}


int main(int argc, char **argv)
{

	if (argc != 3)
		return -1;
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		write(1, "0\n", 2);
		return 0;
	}
	if (argv[1][0] == '-' && argv[2][0] != '-')
		write(1, "-", 1);
	if (argv[1][0] != '-' && argv[2][0] == '-')
		write(1, "-", 1);
	if (argv[1][0] == '-')
		argv[1]++;
	if (argv[2][0] == '-')
		argv[2]++;
	multiply(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}
