#include <stdio.h>
#include <stdlib.h> /* malloc */

struct node
{
    int data;
    struct node *next;
};

void print_linked_list(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("[%d]", curr->data);
        if ((curr = curr->next) != NULL)
            printf("->");
    }
    printf("\n");
}

struct node * generate_linked_list(int n){
    struct node *head = NULL;
    struct node *curr = NULL;
    int i = 0;
    while(i < n){
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        if(head == NULL){
            head = new_node;
            curr = new_node;
        }else{
            curr->next = new_node;
            curr = new_node;
        }
        i++;
    }
    curr->next = NULL;

    return head;
}

struct node * reverse_linked_list(struct node *head){
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}

void debug()
{
    printf("Size of struct node: [%lu] bytes\n", sizeof(struct node));
    printf("Size of int: [%lu] bytes\n", sizeof(int));
    printf("Size of struct node *: [%lu] bytes\n", sizeof(struct node *));
    printf("Size of list of struct node of len [%d]: [%lu] bytes\n", 10, 10 * sizeof(struct node));
}

int main()
{

    debug();

    struct node *head = NULL;
    head = generate_linked_list(10);
    print_linked_list(head);
    head = reverse_linked_list(head);
    print_linked_list(head);

    return 0;
}