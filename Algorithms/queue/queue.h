#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next, *prev;
};

struct pointers {
  struct node *head, *tail;
};

void enqueuetail(struct pointers *point, int data);
void dequeuehead(struct pointers *point);
void enqueuehead(struct pointers *point, int data);
void dequeuetail(struct pointers *point);
void printqueuetail(struct pointers point);
void printqueuehead(struct pointers point);

#endif
