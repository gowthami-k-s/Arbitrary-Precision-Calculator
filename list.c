#include "header.h"
void create_list(char *opr, Node **head, Node **tail)
{
    // removing pre zeroes
    while(*opr == '0' &&(*opr + 1) != '\0')
    {
        opr++;
    }

    while(*opr != '\0')
    {
        insert_last(head, tail, *opr - '0' );
        opr++;
    }

}

int insert_first(Node **head, Node **tail, int data)
{
    Node *new = malloc(sizeof(Node));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }

    new->next = *head;
    new->prev = NULL;
    new->data = data;

    if(*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }
}
int insert_last(Node **head, Node **tail, int data)
{
    Node *new = malloc(sizeof(Node));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }

    new->next = NULL;
    new->prev = *tail;
    new->data = data;

    if(*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
}
int delete_list(Node **head, Node **tail)
{
    while(*head != NULL)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = *tail = NULL;
}
void print_list(Node *head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}