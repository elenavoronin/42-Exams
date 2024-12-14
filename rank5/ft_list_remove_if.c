// Remove node from linked list, if function cmp returns 0. Allowed functions: free.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list {
	void			*data;
	struct s_list	*next;
}	t_list;


int cmp (void *list_data, void *data)
{
	return strcmp((char*)list_data, (char*)data);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void*, void*))
{
	t_list *curr = (*begin_list);
	t_list *prev = NULL;
	t_list *temp;

	while(curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			temp = curr;
			curr = curr->next;
			if (prev)
				prev->next = curr;
			else
				(*begin_list) = curr;
			free(temp);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}

}

t_list *new_node(void *data)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new)
		return NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}


void add_back(t_list **list, void *data)
{
	t_list *new = new_node(data);
	if (!new)
		return;
	if (!(*list))
	{
		(*list) = new;
		return ;
	}
	t_list *temp = (*list);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void print_list(t_list *list)
{
	t_list *temp = list;
	while(temp)
	{
		printf("%s\n", (char *)temp->data);
		temp = temp->next;
	}
}

int main()
{
	t_list *list = NULL;
	add_back(&list, "a");
	add_back(&list, "b");
	add_back(&list, "c");
	add_back(&list, "d");
	ft_list_remove_if(&list, "a", cmp);
	print_list(list);

	return 0;
}
