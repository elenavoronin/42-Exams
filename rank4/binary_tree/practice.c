#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
}	t_node;


t_node *init(int value)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->right = NULL;
    node->right = NULL;
    return (node);
}

t_node *create(t_node *node, int value)
{
    t_node *current = init(value);
    if (!node)
    {
        node = current;
        return(node);
    }
    if (node->value > value)
        node->left = create(node->left, value);
    else
        node->right = create(node->right, value);
    return(node);
}

int tree_size(t_node *tree)
{
    int size_l = 0;
    int size_r = 0;
    if (!tree)
        return (0);
    int size = 1;
    if (tree->left)
        size_l = tree_size(tree->left);
    if (tree->right)
        size_r = tree_size(tree->right);
    size = size + size_l + size_r;
    return (size);
}

int tree_height(t_node *tree)
{
    int size;
    if (!tree)
        return (-1);
    size = 1;
    int size_l = tree_height(tree->left);
    int size_r = tree_height(tree->right);
    if (size_l > size_r)
        return (size + size_l);
    return (size + size_r);

}

int main()
{
    t_node *tree;
    // int spaces = 0;

    tree = NULL;
    tree = create(tree, 500);
    tree = create(tree, 10);
    tree = create(tree, 3);
    tree = create(tree, 50);
    tree = create(tree, 6);
    tree = create(tree, 22);
    // print_tree(tree, spaces);
    // printf("smallest is %d\n", smallest(tree));
    // printf("biggest is %d\n", biggest(tree));
    printf("tree size = %d\n", tree_size(tree));
    printf("tree height = %d\n", tree_height(tree));
    // find_num(tree, 6);
    // swap_tree(tree);
    // print_tree(tree, spaces);
    // printf("sum = %d\n", sum_tree(tree));
}