#include <stdio.h>

int main(){
    int person[4][3];
    int sum[3] = {0};
    float ratio[3];
    int h[3] = {24,24,48};
    char word[3][10] = {"Men", "Women", "Total"};
    int i,j;

    printf("Check room (Men)\n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("Room #%d > ", 101+100*i+j);
            scanf("%d", &person[i][j]);
            sum[0] += person[i][j];
            sum[2] += person[i][j];
        }
    }
    printf("Check room (Women)\n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("Room #%d > ", 301+100*i+j);
            scanf("%d", &person[i+2][j]);
            sum[1] += person[i+2][j];
            sum[2] += person[i+2][j];
        }
    }

    for(i=0; i<3; i++){
        ratio[i] = sum[i]*100.0 / h[i];
    }

    printf("Check Result\n");
    for(i=0; i<3; i++){
        printf("%s: %d/%d(%.1f%%)\n", word[i], sum[i],h[i],ratio[i]);
    }

    return 0;
}