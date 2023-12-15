#include<stdio.h>

void bankers(int allocation[5][3], int need[5][3],int available[3] ) {
    int complete[5] = {0};
    int process_sequence[5];
    int k = 0, flag = 0;

    for(int i=0;i<5;i++) {
        flag = 0;
        if(complete[i]==0) {
            for(int j=0;j<3;j++) {
                if(need[i][j] >available[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) {
                complete[i] = 1;
                process_sequence[k++] = i;

                for(int m=0;m<3;m++) {
                    available[m] +=  allocation[i][m];
                }
                i = -1;
            }
        }
    }
    flag = 0;
    for(int i=0;i<5;i++){
        if(complete[i]==0){
            printf("\ndead lock present");
            flag = 1;
            break;
        }
    }
    if(flag==0) {
        printf("\nsystem is free from deadloack ");
        for(int i=0;i<4;i++) {
             printf("P%d-->",process_sequence[i]);
        }
        printf("P%d",process_sequence[4]);
    }

    
}

int main() {
    // number of processes
    int n = 5;

    // number of resource
    int m = 3;

    int allocation[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
     
    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int need[5][3] = {
        {7,4,3},
        {1,2,2},
        {6,0,0},
        {0,1,1},
        {4,3,1}
    };

    int aviable[3] = {3,3,2};
    bankers(allocation,need,aviable);
}