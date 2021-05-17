#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, sumTime;
    int schedule[30], minMaxTime[2][30] ;
    int i;

    do
        scanf("%d%d", &d, &sumTime);
    while (d < 1 || d > 30 || sumTime < 0 || sumTime > 240);

    for (i = 0; i < d; i++)
    {
        scanf("%d%d", &minMaxTime[0][i], &minMaxTime[1][i]);
    }

    int minT = 0, maxT = 0;
    for (i = 0; i < d; i++)
    {
        minT += minMaxTime[0][i];
        maxT += minMaxTime[1][i];
        schedule[i] = minMaxTime[0][i];
    }
    if (sumTime < minT || sumTime > maxT)
    {
        printf("NO");
        return 0;
    }

    sumTime -= minT;
    for (i = 0; i < d; i++)
    {
        if (sumTime > 0)
            if (sumTime >= minMaxTime[1][i] - minMaxTime[0][i])
            {
                schedule[i] += minMaxTime[1][i] - minMaxTime[0][i];
                sumTime -= minMaxTime[1][i] - minMaxTime[0][i];
            }
            else
            {
                schedule[i] += sumTime;
                sumTime = 0;
            }
    }
    printf("YES\n");
    for (i = 0; i < d; i++)
    {
        printf("%d ", schedule[i]);
    }
    return 0;
}
