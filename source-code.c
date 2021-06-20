#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int acc;
char input[100];
char tokens[5][20];

void init()
{
    acc = 0;
}

void resetToken()
{
    int i, j;

    for(i=0; i<5; i++)
    {
        for(j = 0; j<20; j++)
        {
            tokens[i][j] = '\0';
        }
    }
}

void takeInput()
{
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);

    input[len-1] = '\0';

    int words = 0, i;

    int r = 0, k = 0;
    for(i=0; input[i]!='\0'; i++)
    {
        tokens[k][r] = '\0';

        if(input[i] == ' ')
        {
            k++;
            r = 0;
        }
        else
        {
            tokens[k][r++] = input[i];
            tokens[k][r] = '\0';
        }

    }
}

void parseCommand()
{
    int x;

    if(!strcmp(tokens[0], "ADD"))
    {
        x = atoi(tokens[1]);
        acc = acc + x;

        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "SUB"))
    {
        x = atoi(tokens[1]);
        acc = acc - x;

        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "MUL"))
    {
        x = atoi(tokens[1]);
        acc = acc * x;
        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "DIV"))
    {
        x = atoi(tokens[1]);
        acc = acc / x;

        if(x == 0)
        {
            printf("Math error! Cannot divide by 0!\n");
        }
        else
        {
            printf("\naccumulator = %d\n", acc);
        }
    }
    else if(!strcmp(tokens[0], "AND"))
    {
        x = atoi(tokens[1]);
        acc = acc & x;

        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "NOT"))
    {
        acc = ~acc;
        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "OR"))
    {
        x = atoi(tokens[1]);
        acc = acc | x;

        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "LD"))
    {
        x = atoi(tokens[1]);
        acc = x;

        printf("\naccumulator = %d\n", acc);
    }
    else if(!strcmp(tokens[0], "ST"))
    {
        printf("\naccumulator = %d\n", acc);
        printf("\nstored in memory location: %p", &acc);
    }

    printf("\n\n");
}

int main()
{
    init();

    printf("Insert command in assembly language: \n\n");
    printf("Format: <opcode> <operand>\n\n");

    while(1)
    {
        resetToken();
        takeInput();
        parseCommand();
    }

    return 0;
}
