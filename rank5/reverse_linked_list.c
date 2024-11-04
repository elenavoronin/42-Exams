#include <stdlib.h>
#include <stdio.h>


typedef struct s_list 
{
	struct s_list	*next;
	char			*content;
} 	t_list;


t_list* new_node(char *content)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void add_back(t_list **list, char *content)
{
	if (!*list)
	{
		*list = new_node(content);
		return ;
	}
	t_list *new = new_node(content);
	t_list *temp = (*list);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void print_list(t_list *list)
{
	t_list *temp = list;
	int i = 1;
	while (temp)
	{
		printf("node[%d]: %s\n", i, temp->content);
		temp = temp->next;
		i++;
	}
}

void reverse_list(t_list **begin_list)
{
	t_list *curr = *begin_list;
	t_list *prev = NULL;
	t_list *next = NULL;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}


int main()
{
	t_list *list = NULL;
	add_back(&list, "1");
	add_back(&list, "2");
	add_back(&list, "3");

	reverse_list(&list);
	print_list(list);
	return 0;
}
