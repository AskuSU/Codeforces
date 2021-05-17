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

NameSpace* insertNameToNameSpace(NameSpace *checkPos, NameSpace *verifiable, short *exist)
{    
    short cmp = strcmp(verifiable->userName, checkPos->userName);
    if (cmp == 0) 
    {
        *exist = 1;
        return checkPos;
    }
    else if (cmp < 0)
    {
        if (!checkPos->leftName)
        {
            checkPos->leftName = verifiable;
            return verifiable;
        }
        else
        {
            return(insertNameToNameSpace(checkPos->leftName, verifiable, exist));
        }
    }
    else if (cmp > 0)
    {
        if (!checkPos->rightName)
        {
            checkPos->rightName = verifiable;
            return verifiable;
        }
        else
        {
            return(insertNameToNameSpace(checkPos->rightName, verifiable, exist));
        }
    }
    
}

NameSpace firstEmptyName;

int main(){
    int N;
    /*
    FILE *inputF, *outputF;
    
    inputF = fopen("input.txt", "r");
    //outputF = fopen("output.txt", "w");
    fscanf(inputF,"%d", &N);
    */
    scanf("%d", &N);
    NameSpace *listNames;
    listNames = (NameSpace*)calloc(N, N * sizeof(NameSpace));
    for (int i = 0; i < N; i++)
    {
        NameSpace* currentName = listNames + i;
        scanf("%32s", currentName->userName);
        //fscanf(inputF, "%32s", currentName->userName);        
        //fgets(strings + i*lengthS*sizeof(char), lengthS, stdin);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        short exist = 0;
        NameSpace *currentName = listNames + i;
        NameSpace *element = insertNameToNameSpace(&firstEmptyName, currentName, &exist);
        if (exist)        
            printf("%s%d\n", element->userName, element->cntUsages);       
        else printf("OK\n"); 
        element->cntUsages++;  
    }
    return 0;
}