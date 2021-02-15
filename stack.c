#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "stack.h"
int main()
{
    printf("For int:\n");
    stack(int);
    int_stack v;
    int_stack_init(&v);
    int_stack_push(&v, 5);
    int_stack_push(&v, 10);
    int_stack_push(&v, 15);
    printf("Stack Size is: %lu \n", int_stack_size(&v));
    printf("%d was popped\n", int_stack_pop(&v));
    printf("Stack Size is: %lu \n", int_stack_size(&v));
    printf("Element at index 1 is: %d \n", int_stack_get(&v, 1));
    printf("Stack top: %d \n", int_stack_top(&v));
    int_stack_set(&v, 1, 34);
    printf("Stack top: %d \n", int_stack_top(&v));
    printf("\n---------------------------------\n");
    printf("For char:\n");
    stack(char);
    char_stack v1;
    char_stack_init(&v1);
    char_stack_push(&v1, 'a');
    char_stack_push(&v1, '$');
    char_stack_push(&v1, 'z');
    printf("Stack Size is: %lu \n", char_stack_size(&v1));
    printf("%c was popped\n", char_stack_pop(&v1));
    printf("Stack Size is: %lu \n", char_stack_size(&v1));
    printf("Element at index 1 is: %c \n", char_stack_get(&v1, 1));
    printf("Stack top: %c \n", char_stack_top(&v1));
    char_stack_set(&v1, 1, '@');
    printf("Stack top: %c \n", char_stack_top(&v1));
}