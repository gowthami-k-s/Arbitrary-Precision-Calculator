#include "header.h"

void division(Node *head1, Node *tail2, Node **headR, Node **tailR)
{
    int count = 0;
    Node *temp_head = NULL, *temp_tail = NULL;
    Node *add_head = NULL, *add_tail = NULL;

    insert_first(&temp_head, &temp_tail, 0);
    while(1)
    {
        add_head = NULL;
        add_tail = NULL;

        addition(temp_tail, tail2, &add_head, &add_tail);

        if(compare_list(add_head, head1) == OPERAND1)
        {
            delete_list(&add_head, &add_tail);
            break;
        }

        count++;
        delete_list(&temp_head, &temp_tail);
        temp_head = add_head;
        temp_tail = add_tail;

        if(compare_list(add_head, head1) == SAME)
        {
            break;
        }
    }
    insert_first(headR, tailR, count);
    delete_list(&temp_head, &temp_tail);
}