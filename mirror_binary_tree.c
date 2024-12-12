// In a binary tree, reverse left and right branches
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_tree {
    int data;                // Data stored in the node
    struct s_tree *left;     // Pointer to the left child
    struct s_tree *right;    // Pointer to the right child
} t_tree;

void mirror_binary_tree(t_tree *root)
{

}




void print_tree(t_list *list)
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
	t_tree *tree = NULL;
	
	return 0;
}
