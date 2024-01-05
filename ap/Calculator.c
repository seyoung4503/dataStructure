
#include "Calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.'};

int IsNumber(char Cipher)
{
    int i = 0; 
    int ArrayLength = sizeof(NUMBER);

    for (i = 0; i < ArrayLength; i++) 
    {
        if (Cipher == NUMBER[i])
            return 1;
    }
    return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
    unsigned int i = 0;

    for (i = 0; 0 != Expression[i]; i++) 
    {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == 1)
        {
            *TYPE = OPERAND;
            
            if (IsNumber(Expression[i+1]) != 1)
                break;
        }
        else
        {
            *TYPE = Expression[i];
            break;
        }
    }

    Token[++i] = '\0';
    return i;
}

int GetPriority(char Operator, int InStack)
{
    int Priority = -1;

    switch (Operator)
    {
    case LEFT_PARENTHESIS:
        if (InStack)
            Priority = 3;
        else
            Priority = 0;
        break;
    
    case MULTIPLY:
    case DIVIDE:
        Priority = 1;
        break;
    
    case PLUS:
    case MINUS:
        Priority = 2;
        break;
    }

    return Priority;
}

int IsPrior(char Operator1, char Operator2)
{
    return GetPriority(Operator1, 1) > GetPriority(Operator2, 0);
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
    ArrayStack* Stack;

    char Token[32];
    int Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);
    //unsigned int capacity = Length;

    AS_CreateStack(&Stack, Length);

    while (Position < Length) 
    {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == OPERAND)
        {
            strcat(PostfixExpression, Token);
        }
    }
}

double Calculate(char* PostfixExpression);