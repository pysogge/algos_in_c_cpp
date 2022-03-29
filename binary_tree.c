#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *generate_binary_tree(struct node *root, int low, int high)
{
    struct node *curr = root;
    int i = low;
    if (i < high)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;

        printf("new node: %d\n", i);

        if (root == NULL)
        {
            root = new_node;
            i++;
        }

        curr = root;

        if (i < high)
        {
            // randomly 50% choose to add a left node
            if ((i < high) && ((rand() % 9) < 5))
            {
                curr->left = generate_binary_tree(NULL, i, high);
                i++;
            }
            // then randomly 50% choose to add a right node
            if ((i < high) && ((rand() % 9) < 5))
            {
                curr->right = generate_binary_tree(NULL, i, high);
                i++;
            }
        }
    }

    return root;
}

void print_binary_tree(struct node *root)
{
    struct node *curr = root;
    int left = 0, right = 0;
    while (curr->left != NULL)
    {
        curr = curr->left;
        left++;
    }
    curr = root;
    while (curr->right != NULL)
    {
        curr = curr->right;
        right++;
    }
    printf("head d[%d] with left[%d] and right[%d]\n", root->data, left, right);
}

void print_flat_tree(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
    }
    printf("[");
    if (root->left != NULL)
    {
        print_flat_tree(root->left);
    }
    printf(",");
    if (root->right != NULL)
    {
        print_flat_tree(root->right);
    }
    printf("]");
}

int main()
{
    struct node *binary_tree = NULL;
    binary_tree = generate_binary_tree(binary_tree, 0, 10);
    print_binary_tree(binary_tree);
    print_flat_tree(binary_tree);

    return 0;
}

/*

0[1[2[7],3],4[5,6]]

       0
     /   \
    1      4
   / \     / \
  2   3   5   6
 /
7
*/