#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
  struct pointers point = {NULL, NULL};
  enqueuetail(&point, 3);
  enqueuetail(&point, 2);
  enqueuetail(&point, 1);
  enqueuehead(&point, 4);
  enqueuehead(&point, 5);
  puts("Print from head:");
  printqueuehead(point);
  puts("Print from tail:");
  printqueuetail(point);
  puts("Dequeue head and print from head:");
  dequeuehead(&point);
  printqueuehead(point);
  puts("Dequeue tail and print from tail:");
  dequeuetail(&point);
  printqueuetail(point);
  return 0;
}
