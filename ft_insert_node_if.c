// Insert node at the END of the binary tree, if value of new node is bigger than root value  - insert at END of right branch, 
// otherwise insert at END of left branch. Ignore all duplicates. Allowed functions: malloc, free.
// it tree = NULL, new node is the root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_tree {
    int data;                // Data stored in the node
    struct s_tree *left;     // Pointer to the left child
    struct s_tree *right;    // Pointer to the right child
} t_tree;


t_tree *new_node(int data)
{
	t_tree *new = malloc(sizeof(t_tree));
	if (!new)
		return NULL;
	new->data = data;
	new->right = NULL;
	new->left = NULL;
	return new;

}

void ft_insert_node_if(t_tree **tree, int data)
{
	t_tree *new = new_node(data);
	if (!new)
		return ;
	if (!(*tree))
	{
		(*tree) = new;
		return;
	}
	t_tree *temp = (*tree);
	if (data > temp->data)
	{
		while (temp->right != NULL)
			temp = temp->right;
		temp->right = new;
	}	
	else if (data < temp->data)
	{
		while (temp->left != NULL)
			temp = temp->left;
		temp->left = new;
	}
}


void print_tree(t_tree *tree) {
    if (!tree) {
        return;
    }
    print_tree(tree->left);
    printf("%d\n", tree->data);
    print_tree(tree->right);
}

// Function to free the tree
void free_tree(t_tree *tree) {
    if (!tree) {
        return;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

// Main function to test the tree insertion
int main() {
    t_tree *tree = NULL;

    // Insert nodes into the binary tree
    ft_insert_node_if(&tree, 10);
    ft_insert_node_if(&tree, 5);
    // ft_insert_node_if(&tree, 15);
    ft_insert_node_if(&tree, 3);
    // ft_insert_node_if(&tree, 7);
    // ft_insert_node_if(&tree, 12);
    // ft_insert_node_if(&tree, 18);
    // ft_insert_node_if(&tree, 7); // Duplicate, should be ignored

    // Print the tree in-order
    printf("In-order traversal of the tree:\n");
    print_tree(tree);
    printf("\n");

    // Free the allocated memory
    free_tree(tree);

    return 0;
}
