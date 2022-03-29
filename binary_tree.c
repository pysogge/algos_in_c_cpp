#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAXSTACK 100

static int sp = -1;
char cstack[MAXSTACK];

void stack_push(char c)
{
    if (sp < (int)MAXSTACK)
    {
        cstack[++sp] = c;
    }
    else
    {
        printf("Error MAXSTACKSIZE = [%d] Exceeded.\n", (int)MAXSTACK);
    }
}

void clear_stack()
{
    sp = -1;
    cstack[0] = '\0';
}

char stack_pop()
{
    if (sp > 0)
    {
        return cstack[sp--];
    }
    else if (sp == 0)
    {
        char c = cstack[sp--];
        cstack[0] = '\0';
        return c;
    }
    else
    {
        printf("!ERROR: STACK UNDERFLOW\n");
        return -1;
    }
}

char stack_top(int n)
{
    if (sp >= n)
    {
        return cstack[sp - n];
    }
    else if (n == 0 && sp == -1)
    {
        return cstack[0];
    }
    else
    {
        // printf("!ERROR: STACK UNDERFLOW\n");
        return -1;
    }
}

void print_stack()
{
    cstack[sp + 1] = '\0';
    printf("P: [%d], STACK: %s\n", sp, cstack);
}

/*

Flat Tree Notation:

0[1[2[7[,]],3[,]],4[5[,],6[,]]]

Represents:

       0
     /   \
    1     4
   / \    / \
  2   3  5   6
 /
7

Depth = 3 (starts at 0)

*/

struct node
{
    int data;
    struct node *left, *right;
};

bool is_valid_tree_notation(char tree_notation[])
{
    bool is_valid = false;
    int i = 0;
    char c, tmp;
    while (((c = tree_notation[i]) != '\0') && (i < (int)MAXSTACK))
    {
        if ((c == '[') || (c == ','))
        {
            stack_push(c);
        }
        else if (c == ']')
        {
            /* if top of stack is [, */
            if (stack_top(0) == ',' && stack_top(1) == '[')
            {
                stack_pop();
                stack_pop();
            }
            else
            {
                stack_push(c);
            }
        }
        i++;
    }

    if (stack_top(0) == '\0')
        is_valid = true;

    return is_valid;
}

int get_tree_depth(struct node *root, int level)
{
    int deepest = level;
    int tmplevel;
    if (root->left != NULL)
        if ((tmplevel = get_tree_depth(root->left, level + 1)) > deepest)
            deepest = tmplevel;

    if (root->right != NULL)
        if ((tmplevel = get_tree_depth(root->right, level + 1)) > deepest)
            deepest = tmplevel;

    return deepest;
}

struct node *generate_random_binary_tree(struct node *root, int low, int high)
{
    struct node *curr = root;
    int i = low;
    if (i < high)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;

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
                curr->left = generate_random_binary_tree(NULL, i, high);
                i++;
            }
            // then randomly 50% choose to add a right node
            if ((i < high) && ((rand() % 9) < 5))
            {
                curr->right = generate_random_binary_tree(NULL, i, high);
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

void unit_tests()
{
    stack_push('a');
    stack_push('b');
    stack_push('c');
    print_stack();
    printf("popping: %c\n", stack_pop());
    print_stack();
    printf("popping: %c\n", stack_pop());
    printf("popping: %c\n", stack_pop());
    print_stack();

    char tree1[] = "0[,]";
    printf("->%s<- is valid: %d\n", tree1, is_valid_tree_notation(tree1));
    print_stack();
    clear_stack();
    char tree2[] = "0[1[2[7],3],4[5,6]]]]";
    printf("->%s<- is valid: %d\n", tree2, is_valid_tree_notation(tree2));
    print_stack();
    clear_stack();
    char tree3[] = "0[1[2[,3[,]],],2[3[4[,5[6[,7[8[9[,],],9[,]]],7[,8[9[,],]]]],5[,]],]]";
    printf("->%s<- is valid: %d\n", tree3, is_valid_tree_notation(tree3));
    print_stack();
}

int main()
{

    time_t t;
    /* Intializes random number generator */
    srand((unsigned)time(&t));

    unit_tests();

    struct node *binary_tree = NULL;
    binary_tree = generate_random_binary_tree(binary_tree, 0, 10);
    print_binary_tree(binary_tree);
    print_flat_tree(binary_tree);
    printf("\n");
    printf("tree depth: [%d]\n", get_tree_depth(binary_tree, 0));

    return 0;
}
