#include "header.h"

void multiplication(Node *tail1, Node *tail2, Node **headR, Node **tailR)
{
    Node *temp_head = NULL, *temp_tail = NULL;
    Node *add_head = NULL, *add_tail = NULL;
    Node *res_head = NULL, *res_tail = NULL;
    int carry = 0, shift = 0;

    insert_first(&add_head, &add_tail, 0);
    while(tail1 != NULL)
    {
        Node *temp1 = tail2;
        while(temp1 != NULL)
        {
            int mul = tail1->data *temp1->data + carry;
            if(mul > 9)
            {
                carry = mul / 10;
                mul = mul % 10;
            }
            else
            {
                carry = 0;
            }
            insert_first(&temp_head, &temp_tail, mul);
            temp1 = temp1->prev;
        }
        if(carry != 0)
        {
            insert_first(&temp_head, &temp_tail, carry);
        }

        for(int i = 0; i < shift; i++)
        {
            insert_last(&temp_head, &temp_tail, 0);
        }

        addition(temp_tail, add_tail, &res_head, &res_tail);

        delete_list(&add_head, &add_tail);
        delete_list(&temp_head, &temp_tail);

        add_head = res_head;
        add_tail = res_tail;

        res_head = NULL;
        res_tail = NULL;

        tail1 = tail1->prev;
        shift++;
    }

    *headR = add_head;
    *tailR = add_tail;
}
