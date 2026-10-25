#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SUCCESS		1
#define FAILURE		0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Node;

void addition(Node *tail1, Node *tail2, Node **headR, Node **tailR);
void subtraction(Node *tail1, Node *tail2, Node **headR, Node **tailR);
void multiplication(Node *tail1, Node *tail2, Node **headR, Node **tailR);
void division(Node *head1, Node *head2, Node **headR, Node **tailR);

int cla_validation(int argc, char *argv[]);
void create_list(char *opr, Node **head, Node **tail);

int insert_first(Node **head, Node **tail, int data);
int insert_last(Node **head, Node **tail, int data);
int delete_list(Node **head, Node **tail);
void print_list(Node *head);

int compare_list(Node *head1, Node *head2);
int list_len(Node *head);

#endif
