#include "header.h"

void subtraction(Node *tail1, Node *tail2, Node **headR, Node **tailR)
{
    int borrow = 0;
    while(tail1 != NULL)
    {
        int diff = tail1->data - borrow;

        if(tail2 != NULL)
        {
            diff -= tail2->data;
            tail2 = tail2->prev;
        }
        
        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        tail1 = tail1->prev;

        // Insert difference in the result list
        insert_first(headR, tailR, diff);
    }

    // remove pre zeroes from result list
    while(*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Node *temp = *headR;
        *headR = (*headR)->next;
        free(temp);
    }
}
