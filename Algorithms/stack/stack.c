#include "stack.h"

void push(struct node **top, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node *));
  if(new_node != NULL) {
      new_node->next = *top;
      *top = new_node;
      new_node->data = data;
  }

}

void pop(struct node **top) {
  if(*top != NULL) {
    struct node *tmp = *top;
    free(*top);
    *top = tmp->next;
  }

}

void printstack(struct node *top) {
  if(top==NULL) {
    puts("Stack empty!");
  }
  else {
    while(top != NULL) {
      printf("%d ", top->data);
      top = top->next;
    }
    puts("");
  }
}

void deletestack(struct node **top) {
  while(*top != NULL) {
    struct node *tmp = (*top)->next;
    free(*top);
    *top = NULL;
    *top = tmp;
  }
}

int peek(struct node *top) {
  if(top != NULL)
    return top->data;
  else
    return -1;
}
