//
//  main.c
//  2
//
//  Created by Matthew Lee on 02/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *in = fopen("/Users/matthewlee/Downloads/input-2.txt", "r");
    int total = 0;
    char x[2];
    char y[2];
    
    while (fscanf(in, "%s %s", x, y) != EOF)
    {
        if (y[0] == 'X')
        {
            if (x[0] == 'A')
                total += 3;
            else if (x[0] == 'B')
                total += 1;
            else if (x[0] == 'C')
                total += 2;
        }
        
        else if (y[0] == 'Y')
        {
            if (x[0] == 'A')
                total += 1;
            else if (x[0] == 'B')
                total += 2;
            else if (x[0] == 'C')
                total += 3;
            total += 3;
        }
        
        else if (y[0] == 'Z')
        {
            if (x[0] == 'A')
                total += 2;
            else if (x[0] == 'B')
                total += 3;
            else if (x[0] == 'C')
                total += 1;
            total += 6;
        }
    }
    
    /*while (fscanf(in, "%s %s", x, y) != EOF)
    {
        if (y[0] == 'X')
        {
            if (x[0] == 'C')
                total += 6;
            else if (x[0] == 'A')
                total += 3;
            total++;
        }
        else if (y[0] == 'Y')
        {
            if (x[0] == 'A')
                total += 6;
            else if (x[0] == 'B')
                total += 3;
            total += 2;
        }
        else if (y[0] == 'Z')
        {
            if (x[0] == 'B')
                total += 6;
            else if (x[0] == 'C')
                total += 3;
            total += 3;
        }
    }*/
    printf("%d\n", total);
    fclose(in);
}
