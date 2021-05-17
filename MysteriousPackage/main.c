#include <stdio.h>
#include <malloc.h>

typedef struct rectangle
{
    int w, h, index;
} Rectangle;

void quicksort(int *l, int *r){
    if (r - l <= 1) return;
    //int z = *(l + (r - 1));  
}

int main(){
    int N;
    Rectangle postcard;
    scanf("%d%d%d", &N, &postcard.w, &postcard.h);
    Rectangle *envelopes;
    envelopes = (Rectangle*)calloc(N, sizeof(Rectangle));
    for (int i = 0; i < N; i++)
    {
        Rectangle *currEnvel = envelopes + i;
        scanf("%d%d", &currEnvel->w, &currEnvel->h);
        currEnvel->index = i;
    }
    

    //printf("%d %d %d", N, envelopes->w, envelopes->h);
    return 0;
}