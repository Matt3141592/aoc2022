//
//  main.c
//  6
//
//  Created by Matthew Lee on 06/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void part1(void);
void part2(void);
int header(char arr[], int x);

int main(void)
{
    clock_t begin = clock();
    FILE *in = fopen("/Users/matthewlee/Downloads/input-6.txt", "r");
    char str[10000];
    fscanf(in, "%s", str);
    fclose(in);
    
    int count = 4;
    char arr[14];
    
    while (str[count])
    {
        for (int i = 1; i < 5; i++)
            arr[i - 1] = str[count - i];
        if (header(arr, 4))
            break;
        count++;
    }
    printf("%d\n", count);
    
    while (str[count])
    {
        for (int i = 1; i < 15; i++)
            arr[i - 1] = str[count - i];
        if (header(arr, 14))
            break;
        count++;
    }
    printf("%d\n", count);
    
    printf("%f\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
}

void part1(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-6.txt", "r");
    char str[10000];
    fscanf(in, "%s", str);
    int count = 4;
    char arr[4];
    
    while (str[count])
    {
        for (int i = 1; i < 5; i++)
            arr[i - 1] = str[count - i];
        if (header(arr, 4))
            break;
        count++;
    }
    
    printf("%d\n", count);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-6.txt", "r");
    char str[10000];
    fscanf(in, "%s", str);
    int count = 14;
    char arr[14];
    
    while (str[count])
    {
        for (int i = 1; i < 15; i++)
            arr[i - 1] = str[count - i];
        if (header(arr, 14))
            break;
        count++;
    }
    printf("%d\n", count);
    fclose(in);
}

int header(char arr[], int x)
{
    for (int i = 0; i < x; i++)
        for (int j = i + 1; j < x; j++)
            if (arr[i] == arr[j])
                return 0;
    return 1;
}
