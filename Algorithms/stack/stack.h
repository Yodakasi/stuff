#ifndef STOS_H_
#define STOS_H_
#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

void push(struct node **top, int data);
void pop(struct node **top);
void printstack(struct node *top);
void deletestack(struct node **top);
int peek(struct node *top);

#endif
