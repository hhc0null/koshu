#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *beg = NULL, limit;

    scanf("%d", &limit);
    beg = (int *)calloc(sizeof(int), limit-1);
    for(int i = 0; i < limit-1; i++)
        *(beg+i) = i+2;

    for(int *div = beg; div-beg < limit-1; div++) {
        if(*div == 0)
            continue;
        for(int *ptr = div+1; ptr-beg < limit-1; ptr++)
            if(*ptr % *div == 0) 
                *ptr = 0;
    }

    for(int i = 0; i < limit-1; i++) {
        if(*(beg+i) != 0)
            printf("%d\n", *(beg+i));
        else
            continue;
    }

    free(beg);

    return 0;
}
