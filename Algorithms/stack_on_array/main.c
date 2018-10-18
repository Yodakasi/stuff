#include <stdlib.h>
#include <stdio.h>

#define N 5

void push(int *stos, int *top, int data) {
  if(*top < N-1) {
    (*top)++;
    stos = stos + *top;
    *stos = data;
  }
}

void pop(int *stos, int *top) {
  if(*top > -1) {
    stos = stos + *top;
    (*top)--;
    *stos = 0;
  }
}

void printstack(int *stos, int top) {
  for(int i=top; i>=0; i--) {
    printf("%d\n", *(stos + i));
  }
}

int main() {
  int stos[N];
  int top = -1;
  push(stos, &top, 3);
  push(stos, &top, 2);
  push(stos, &top, 1);
  printstack(stos, top);
  puts("Pop stack:");
  pop(stos, &top);
  printstack(stos, top);
  puts("Push 4 and 5 to the stack:");
  push(stos, &top, 4);
  push(stos, &top, 5);
  printstack(stos, top);
  puts("Pop Stack twice");
  pop(stos, &top);
  pop(stos, &top);
  printstack(stos, top);
  return 0;
}
