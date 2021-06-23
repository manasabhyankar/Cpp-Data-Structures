#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(){
    /* Getting warmed up. */
    int *arr = (int*)malloc(100 * sizeof(int));
    for(int i=0; i<100; i++){
        arr[i] = ((i+3)/2) % 4;
        printf("%i", arr[i]);
    }
    printf("\n");

    /* Double pointer stuff. */
    char **blob;
    int temp = 0;
    char c;
    blob = (char**)malloc(sizeof(char(*)) * 50);
    for(int i=0; i<50; i++){
        blob[i] = (char*) malloc(100 * sizeof(char));
        for(int j=0; j<50; j++){
            if(j == 49){
                c = '\0';
            }
            else{
                temp = rand() % 2;
                if(temp == 0){
                    c = (rand() % 26) + 65;
                    printf("%i : %c\n", c, c);
                }
                else{
                    c = (rand() % 26) + 97;
                    printf("%i : %c\n", c, c);
                }
            }
            blob[i][j] = c;
        }
    }
    for(int i=0; i<50; i++){
        printf("String %i: %s\n", i, blob[i]);
    }
    
    printf("\n");

}

/*
    - Cannot use memset on non-char array pointers.
    - For 2D arrays, just be careful of how you've allocated the pointer to the pointers
    in terms of memory allocation. Double/triple-check the cast during the malloc call.
*/