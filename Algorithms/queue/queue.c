#include "queue.h"


void enqueuetail(struct pointers *point, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if(newNode != NULL) {
    newNode->data = data;
    newNode->prev = point->tail;
    newNode->next = NULL;
    if(point->tail != NULL) {
      point->tail->next = newNode;
    }
    else {
      point->head = newNode;
    }
    point->tail = newNode;
  }
}

void dequeuehead(struct pointers *point) {
  if(point->head != NULL) {
    struct node *tmp = point->head->next;
    free(point->head);
    point->head = tmp;
    if(tmp == NULL) {
      point->tail = NULL;
    }
    else {
      point->head->prev = NULL;
    }
  }
}

void enqueuehead(struct pointers *point, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if(newNode != NULL) {
    newNode->data = data;
    newNode->next = point->head;
    newNode->prev = NULL;
    if(point->head == NULL) {
      point->tail = newNode;
    }
    else {
      point->head->prev = newNode;
    }
    point->head = newNode;
  }
}

void dequeuetail(struct pointers *point) {
  if(point->tail != NULL) {
    struct node *tmp = point->tail->prev;
    free(point->tail);
    point->tail = tmp;
    if(tmp == NULL) {
      point->head = NULL;
    }
    else {
      point->tail->next = NULL;
    }
  }
}

void printqueuetail(struct pointers point) {
  while(point.tail != NULL) {
    printf("%d ", point.tail->data);
    point.tail = point.tail->prev;
  }
  puts("");
}

void printqueuehead(struct pointers point) {
  while(point.head != NULL) {
    printf("%d ", point.head->data);
    point.head = point.head->next;
  }
  puts("");
}
/*
void enqueue_front(struct queue_pointers *queue,int data)
{
    struct queue_node *new_node = (struct queue_node *)malloc(sizeof(struct queue_node));
    new_node->prev = NULL;
    new_node->data = data;
    if(new_node!=NULL)
    {
        if(queue->head==NULL)
        {
            queue->head=queue->tail=new_node;
        }
        else
        {

            new_node->next = queue->head;
            queue->head->prev = new_node;
            queue->head = new_node;
        }
    }
}

void enqueue_back(struct queue_pointers *queue,int data)
{
    struct queue_node *new_node = (struct queue_node *)malloc(sizeof(struct queue_node));
    new_node->next = NULL;

    new_node->data = data;
    if(new_node!=NULL)
    {
        if(queue->head==NULL)
        {
            queue->head=queue->tail=new_node;
        }
        else
        {
             new_node->prev=queue->tail;
             queue->tail->next = new_node;
             queue->tail = new_node;

        }


    }
}*/
