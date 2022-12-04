//
//  main.c
//  4
//
//  Created by Matthew Lee on 04/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void part1(void);
void part2(void);
int within(int a, int b, int c, int d);
int overlap(int a, int b, int c, int d);

int main(void)
{
    clock_t begin = clock();
    part1();
    printf("%f\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
    //part2();
}

void part1(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-4.txt", "r");
    char str[20];
    int arr[4];
    int total = 0;
    int total1 = 0;
    
    while (fscanf(in, "%s", str) != EOF)
    {
        arr[0] = atoi(strtok(str, "-"));
        arr[1] = atoi(strtok(NULL, ","));
        arr[2] = atoi(strtok(NULL, "-"));
        arr[3] = atoi(strtok(NULL, ","));
        
        if (within(arr[0], arr[1], arr[2], arr[3]))
            total++;
        else if (within(arr[2], arr[3], arr[0], arr[1]))
            total++;
        
        if (overlap(arr[0], arr[1], arr[2], arr[3]))
            total1++;
        else if (overlap(arr[2], arr[3], arr[0], arr[1]))
            total1++;
    }
    printf("%d %d\n", total, total1);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-4.txt", "r");
    char str[20];
    int arr[4];
    int total = 0;
    
    while (fscanf(in, "%s", str) != EOF)
    {
        arr[0] = atoi(strtok(str, "-"));
        arr[1] = atoi(strtok(NULL, ","));
        arr[2] = atoi(strtok(NULL, "-"));
        arr[3] = atoi(strtok(NULL, ","));
        
        if (overlap(arr[0], arr[1], arr[2], arr[3]))
            total++;
        else if (overlap(arr[2], arr[3], arr[0], arr[1]))
            total++;
    }
    printf("%d\n", total);
    fclose(in);
}

int within(int a, int b, int c, int d)
{
    if (a >= c)
        if (b <= d)
            return 1;
    return 0;
}

int overlap(int a, int b, int c, int d)
{
    if (a >= c)
        if (d >= a)
            return 1;
    if (b >= c)
        if (b <= d)
            return 1;
    return 0;
}
