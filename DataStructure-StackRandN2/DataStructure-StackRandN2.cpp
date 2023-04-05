#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int data;
} element;

element* stack;  
int top = -1;
int size = MAX_SIZE;  

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (size - 1));
}

void push(element item)
{
    if (is_full())
    {
        fprintf(stderr, "Stack Full!!\n");
        return;
    }
    else stack[++top] = item;
}

element pop(int i)
{
    if (is_empty())
    {
        fprintf(stderr, "Stack Emtpy!!\n");
        printf("[%d] pop: %d\n", i, top);
        element empty_elem = { -1 };
        return empty_elem;
    }
    else {
        printf("[%d] pop : %d\n", i, stack[top].data);
        return stack[top--];
    }
}

int main(void)
{
    srand(time(NULL));
    int rand_num;
    int capacity = MAX_SIZE;
    stack = (element*)malloc(sizeof(element) * capacity);  
    printf("------using dynamic------\n");
    for (int i = 1; i <= 30; i++)
    {
        rand_num = rand() % 100 + 1;
        if (rand_num % 2 == 0)
        {
            element new_elem = { rand_num };
            push(new_elem);
            printf("[%d] push : %d\n", i, rand_num);

            if (top == capacity - 1) {  
                capacity *= 2;
                stack = (element*)realloc(stack, sizeof(element) * capacity);
            }

        }
        else {
            pop(i);
        }
    }

    free(stack);  
    return 0;
}