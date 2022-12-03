//
//  main.c
//  3
//
//  Created by Matthew Lee on 02/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void part1(void);
void part2(void);
int num(int x, char *str);
int fun(char *str, char *str1, char *str2);

int main(void)
{
    part1();
    part2();
}


void part1(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-3.txt", "r");
    char str[100];
    int total = 0;
    
    while (fscanf(in, "%s", str) != EOF)
        total += num((int)strlen(str), str);
        
    printf("%d\n", total);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-3.txt", "r");
    char str[100];
    char str1[100];
    char str2[100];
    int total = 0;
    
    while (fscanf(in, "%s", str) != EOF)
    {
        fscanf(in, "%s", str1);
        fscanf(in, "%s", str2);
        
        total += fun(str, str1, str2);
    }
    printf("%d\n", total);
    fclose(in);
}

int num(int x, char *str)
{
    for (int i = 0; i < (x / 2); i++)
    {
        for (int j = (x / 2); j < x; j++)
        {
            if (str[i] == str[j])
            {
                if (isupper(str[i]))
                    return (str[i] - 38);
                else
                    return (str[i] - 96);
            }
        }
    }
    return 0;
}

int fun(char *str, char *str1, char *str2)
{
    int x = (int)strlen(str);
    int y = (int)strlen(str1);
    int z = (int)strlen(str2);
    
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (str[i] == str1[j])
                for (int k = 0; k < z; k++)
                    if (str[i] == str2[k])
                    {
                        if (isupper(str[i]))
                            return (str[i] - 38);
                        else
                            return (str[i] - 96);
                    }
    return 0;
}
