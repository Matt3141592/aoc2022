//
//  main.c
//  5
//
//  Created by Matthew Lee on 04/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    char x;
    struct node *next;
}node;

void part1(void);
void part2(void);
node *insert_end(node *list, char x);
void freelist(node *list);
char pop(node **list);
node *append(node *list, char x);
node *delete_start(node *list);

int main(void)
{
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
}

void part1(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-5.txt", "r");
    node *stacks[9];
    char str[100];
    
    for (int i = 0; i < 9; i++)
        stacks[i] = NULL;
    
    for (int j = 0; j < 8; j++)
    {
        fgets(str, 100, in);
        for (int i = 1; i < 37; i += 4)
            if (str[i] != ' ')
                stacks[(i - 1) >> 2] = insert_end(stacks[(i - 1) >> 2], str[i]);
    }
    fgets(str, 100, in);
    fgets(str, 100, in);
    
    while (fgets(str, 100, in) != NULL)
    {
        int a = atoi(strtok(str, "moves "));
        int b = atoi(strtok(NULL, " from ")) - 1;
        int c = atoi(strtok(NULL, " to ")) - 1;
        //printf("%i %i %i\n", a, b, c);
        
        for (int i = 0; i < a; i++)
            stacks[c] = append(stacks[c], pop(&stacks[b]));
    }
    
    for (int i = 0; i < 9; i++)
    {
        printf("%c", stacks[i] -> x);
        freelist(stacks[i]);
    }
    printf("\n");
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-5.txt", "r");
    node *stacks[9];
    char str[100];
    
    for (int i = 0; i < 9; i++)
        stacks[i] = NULL;
    
    for (int j = 0; j < 8; j++)
    {
        fgets(str, 100, in);
        for (int i = 1; i < 37; i += 4)
            if (str[i] != ' ')
                stacks[(i - 1) >> 2] = insert_end(stacks[(i - 1) >> 2], str[i]);
    }
    fgets(str, 100, in);
    fgets(str, 100, in);
    
    while (fgets(str, 100, in) != NULL)
    {
        int a = atoi(strtok(str, "moves "));
        int b = atoi(strtok(NULL, " from ")) - 1;
        int c = atoi(strtok(NULL, " to ")) - 1;
        char list[a];
        //printf("%i %i %i\n", a, b, c);
        node *temp = stacks[b];
        for (int i = 0; i < a; i++)
        {
            list[i] = temp -> x;
            temp = temp -> next;
        }
        for (int i = a - 1; i >= 0; i--)
        {
            stacks[c] = append(stacks[c], list[i]);
            stacks[b] = delete_start(stacks[b]);
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        printf("%c", stacks[i] -> x);
        freelist(stacks[i]);
    }
    printf("\n");
    
    fclose(in);
}

node *insert_end(node *list, char x)
{
    node *temp = list;
    node *n = malloc(sizeof(node));
    n -> x = x;
    n -> next = NULL;
    
    if (list == NULL)
        return n;
    
    while (list -> next != NULL)
        list = list -> next;
    list -> next = n;
    return temp;
}

void freelist(node *list)
{
    node *prev = list;
    while (list != NULL)
    {
        list = list -> next;
        free(prev);
        prev = list;
    }
}

char pop(node **list)
{
    node *n = *list;
    if (n != NULL)
    {
        int x = n -> x;
        *list = n -> next;
        free(n);
        return x;
    }
    return 0;
}

node *append(node *list, char x)
{
    node *n = malloc(sizeof(node));
    n -> next = list;
    n -> x = x;
    return n;
}

node *delete_start(node *list)
{
    node *temp = NULL;
    if (list != NULL)
        temp = list -> next;
    free(list);
    return temp;
}
