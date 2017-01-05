#include <stdio.h>

/*
  0
 000
00000     
*/

int main(int argc, char const *argv[]) {
    
    int rows = 0;
    scanf("%d", &rows);
    printf("%d\n", rows);

    printf("\nMerry Christmas, ya filthy animal!\n");

    int i = 0, j = 0;
    int len = (rows * 2); 
    for (i = rows; i > 0; --i)
    {
        for (j = 0; j < i; ++j) {
            printf(" ");
        }

        for (j = 0; j < len; ++j) {
            int half = len / 2;
            if (half + i < j || j < half - i) {
                printf("^");
            } 
        }
        printf("\n");
    }

    int trunk = 0;
    for (i = 0; i < rows; i+=5) {
        trunk += 1;
    }

    for (j = 0; j < trunk; ++j) {
        for (i = 0; i < len; ++i) {
            if (i == (len / 2) - 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");        
    }
     printf("\n..and a happy New Year!\n");
     printf("\n");
    return 0;
}