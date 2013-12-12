#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    unsigned long long int max = 0;
    bool *is_prime = NULL;

    scanf("%Ld", &max);
    max++;
    is_prime = (bool *)calloc(max, sizeof(bool));
    if(is_prime == NULL) {
        puts("cannot allocate memory.");
        exit(EXIT_FAILURE);
    }

    memset(is_prime+2, true, max);
    for(int i = 2; i < max; i++)
        if(*(is_prime+i) == true)
            for(int j = i*2; j < max; j+=i)
                *(is_prime+j) = false;

    for(int i = 0; i < max; i++)
        if(*(is_prime+i) == true)
            printf("%d\n", i);

    free(is_prime);
    return 0;
}
