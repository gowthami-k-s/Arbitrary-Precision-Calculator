#include "header.h"

int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Invalid number of arguments\n");
        return FAILURE;
    }

    if(argv[1] == NULL || argv[3] == NULL)
    {
        printf("Invalid operands\n");
        return FAILURE;
    }

    if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != 'X' && argv[2][0] != '/')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    int i;
    for(i = 0; argv[1][i]; i++)
    {
        if(argv[1][i] == '-' || argv[1][i] == '+')
        {
            if(i != 0)
            {
                printf("Invalid input 1\n");
                return FAILURE;
            }
            continue;
        }

        if(!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            printf("Invalid input 1\n");
            return FAILURE;
        }
    }

    for(i = 0; argv[3][i]; i++)
    {
        if(argv[3][i] == '-' || argv[3][i] == '+')
        {
            if(i != 0)
            {
                printf("Invalid input 2\n");
                return FAILURE;
            }
            continue;
        }
        if(!(argv[3][i] >= '0' && argv[3][i] <= '9'))
        {
            printf("Invalid input 2\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

int compare_list(Node *head1, Node *head2)
{
    if(list_len(head1) > list_len(head2))
    {
        return OPERAND1;
    }
    else if(list_len(head1) < list_len(head2))
    {
        return OPERAND2;
    }
    else
    {
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->data > head2->data)
            {
                return OPERAND1;
            }
            else if(head1->data < head2->data)
            {
                return OPERAND2;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return SAME;
}

int list_len(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}