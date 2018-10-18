#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char const *argv[]) {
  struct node *top = NULL;
  push(&top, 4);
  push(&top, 3);
  push(&top, 2);
  push(&top, 1);
  puts("Print stack:");
  printstack(top);
  puts("Pop once and print stack:");
  pop(&top);
  printstack(top);
  puts("Pop four times and print stack:");
  pop(&top);
  pop(&top);
  pop(&top);
  pop(&top);
  printstack(top);
  puts("Push 5 and 4 and print stack:");
  push(&top, 5);
  push(&top, 4);
  printstack(top);
  deletestack(&top);
  return 0;
}
