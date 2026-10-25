#include "header.h"

void addition(Node *tail1, Node *tail2, Node **headR, Node **tailR)
{
    int carry = 0;
    while(tail1 != NULL || tail2 != NULL)
    {
        int sum = 0;
        if(tail1 != NULL)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }
        if(tail2 != NULL)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        sum += carry;
    
        // Find carry and sum
        if(sum > 9)
        {
            carry = sum /10;
            sum = sum % 10;
        }
        else
        {
            carry = 0;
        }

        //insert sum in the result list
        insert_first(headR, tailR, sum);
    }

    if(carry != 0)
    {
        insert_first(headR, tailR, carry);
    }
}
