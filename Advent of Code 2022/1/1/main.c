//
//  main.c
//  1
//
//  Created by Matthew Lee on 01/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/aoc1", "r");
    char str[10];
    int x;
    int sum = 0;
    int highest[3];
    for (int i = 0; i < 3; i++)
        highest[i] = 0;
    while (fgets(str, 10, in) != NULL)
    {
        x = atoi(str);
        if (x)
            sum += x;
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (sum > highest[i])
                {
                    int temp = highest[i];
                    highest[i] = sum;
                    sum = temp;
                    for (int j = i + 1; j < 3; j++)
                    {
                        temp = highest[j];
                        highest[j] = sum;
                        sum = temp;
                    }
                    break;
                }
            }
            sum = 0;
        }
    }
    int total = 0;
    for (int i = 0; i < 3; i++)
        total += highest[i];
    printf("%d\n", total);
    fclose(in);
}
