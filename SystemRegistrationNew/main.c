#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define lengthName 34

typedef struct nameSpace
{
    char userName[lengthName];
    short cntUsages;
    struct nameSpace *leftName, *rightName;

} NameSpace;

NameSpace* insertNameToNameSpace(NameSpace *previous, NameSpace *verifiable, short *exist)
{
    if (!previous) return verifiable;
    short cmp = strcmp(verifiable->userName, previous->userName);
    if (cmp == 0) 
    {
        *exist = 1;
        return previous;
    }
    else if (cmp < 0)
    {
        if (!previous->leftName)
        {
            previous->leftName = verifiable;
            return verifiable;
        }
        else
        {
            return(insertNameToNameSpace(previous->leftName, verifiable, exist));
        }
    }
    else if (cmp > 0)
    {
        
    }
    
}

NameSpace higherName;

int main(){
    int N;
    
    scanf("%d", &N);
    NameSpace *listNames;
    listNames = (NameSpace*)calloc(N, N * sizeof(NameSpace));
    for (int i = 0; i < N; i++)
    {
        NameSpace* currentName = listNames + i;
        scanf("%32s", currentName->userName);
        //fgets(strings + i*lengthS*sizeof(char), lengthS, stdin);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        short exist;
        NameSpace *currentName = listNames + i;
        NameSpace *newElement = insertNameToNameSpace(&higherName, currentName, &exist);
        if (exist == 0)
                printf("OK\n");
        else    printf("%s%d\n", newElement->userName, newElement->cntUsages);
    }
    return 0;
}