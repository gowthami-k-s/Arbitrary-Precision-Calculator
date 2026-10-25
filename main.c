#include "header.h"

int main(int argc, char *argv[])
{
    Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    // Validation
	if(cla_validation(argc, argv) == FAILURE)
	{
	    return FAILURE;
	}

	int sign1 = 1, sign2 = 1, res_sign = 1;

	//Check sign of operands
	if(*argv[1] == '-' || *argv[1] == '+')
	{
		if(*argv[1] == '-')
		{
			sign1 = -1;
		}
	}
	if(*argv[3] == '-'|| *argv[3] == '+')
	{
		if(*argv[3] == '-')
		{
			sign2 = -1;
		}
	}
    // Create 2 lists of operands
	create_list(argv[1], &head1, &tail1);
	create_list(argv[3], &head2, &tail2);

    char oper = argv[2][0];

    switch(oper)
    {
	case '+':
		if(sign1 == sign2)
		{
	    	addition(tail1, tail2, &headR, &tailR);
		}
		else if(sign1 != sign2)
		{
			if(compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				res_sign = sign1;
			}
			else if(compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				res_sign = sign2;
			}
			else
			{
				insert_first(&headR, &tailR, 0);
			}
		}
		printf("Addition result is : ");
	    break;

	case '-':
		if(sign1 == sign2)
		{
			if(compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
			}
			else if(compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				res_sign = -1;
			}
			else
			{
				insert_first(&headR, &tailR, 0);
			}
		}
		else if(sign1 != sign2)
		{
			if(compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				res_sign = sign1;
			}
			else if(compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				res_sign = sign2;
			}
			else
			{
				insert_first(&headR, &tailR, 0);
			}
		}
		printf("Subtraction result is : ");
	    break;

	case 'x':
	case 'X':
		res_sign = sign1 * sign2;
		multiplication(tail1, tail2, &headR, &tailR);
		printf("Multiplication result is : ");
	    break;

	case '/':
		res_sign = sign1 * sign2;
		division(head1, head2, &headR, &tailR);
		printf("Division result is : ");
	    break;

	default:
	    printf("Invalid operator\n");
    }

	//Print result
	if(res_sign == -1 && headR->data != 0)
	{
		printf("-");
	}
	print_list(headR);
	printf("\n");

	//Delete all lists
	delete_list(&head1, &tail1);
	delete_list(&head2, &tail2);
	delete_list(&headR, &tailR);

}

