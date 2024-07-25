#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

typedef struct s_list
{
    char             *content;
    struct s_list  *next;
}   t_list;

void    free_list(t_list *list)
{
    t_list *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->content);
        free(temp);
    }
}

t_list    *new_node(char *content)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = malloc(sizeof(char) * (ft_strlen(content) + 1)); //try strcpy
    if (!new->content)
    {
        free_list(new);   
        return (NULL);
    }
    strncpy(new->content, content, ft_strlen(content) + 1);
    new->next = NULL;
    return (new);
}

void    add_back(t_list **list, char *content)
{
    t_list *new;
    new = new_node(content);
    if (!new)
        return;
    if (!(*list))
    {
        *list = new;
        return ;
    }
    t_list *temp;
    temp = *list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void    add_front(t_list **list, char *content)
{
    t_list *new;
    new = new_node(content);
    if (!new)
        return;
    new->next = *list;
    *list = new;
}


int compare(t_list *open, char *word)
{
    int i = 0;
    while (open->next != NULL)
    {
        open = open->next;
    }
    if (strcmp(open->content, word) == 0)
    {

        return (0);
    }
    return (1);
}

int validate(char *str)
{
    int i = 0;
    int count = 0;
    int j = 0;
    char   closing[1024];
    char    opening[1024];
    t_list    *open  = NULL;

    if (!str)
        return(-1);
    while(str[i] != '\0')
    {
        if (str[i] == '<' && str[i + 1] != '\0')
        {
            i++;
            if(str[i] != '/')
            {
                count = 0;
                while(str[i] != '>' && str[i] != '\0' && str[i] != ' ')
                {
                    opening[count] = str[i];
                    count++;
                    i++;
                }
                opening[count] = '\0';
                add_back(&open, opening);
                if (!open)
                {
                    free_list(open);
                    free_list(close);
                    return (1);
                }
                // printf("open-> %s\n", open->content);
            }
            else
            {
                j = 0;
                i++;
                while (str[i] != '>' && str[i] != '\0')
                {
                    closing[j] = str[i];
                    j++;
                    i++;
                }
                closing[j] = '\0';
                if (compare(open, closing) == 1)
                {
                    free_list(open);
                    return (1);
                }
            }
        }
        i++;
    }
    free_list(open);
    return (0);
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