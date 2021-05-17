#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define lengthS 34

int main()
{

    int N;
    scanf("%d", &N);
    char *strings;
    strings = (char*)calloc(N*lengthS, N*lengthS * sizeof(char));
    for (int i = 0; i < N; i++)
    {

        scanf("%32s", strings + i*lengthS*sizeof(char));
        //fgets(strings + i*lengthS*sizeof(char), lengthS, stdin);
    }


    printf("\n");
    for (int i = 0; i < N; i++)
    {
        int k = 0;
        char tmpString[lengthS];
        strcpy(tmpString, strings + i*lengthS*sizeof(char));
        for (int j = 0; j < i; j++)
        {            
            if (strcmp(tmpString,strings + j*lengthS*sizeof(char)) == 0)
            {
                k++;
                char p[lengthS] ;
                itoa(k,p,10);
                strcpy(tmpString, strings + i*lengthS*sizeof(char));
                strcat(tmpString, p);
            }
        }
        strcpy(strings + i*lengthS*sizeof(char), tmpString);
        if (k == 0)
            printf("OK\n");
        else printf("%s\n", tmpString);
        //printf("%s\n", strings + i*lengthS*sizeof(char));
    }
    free(strings);

    return 0;
}
