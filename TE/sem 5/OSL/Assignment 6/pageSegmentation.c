#include<stdio.h>
#include<stdlib.h>

void mainMenu();
void FCFS(int frame[3], int pages[5]);
void LRU(int frame[3], int pages[5]);
int check(int arr[]);
int main() {

    
    

    while(1) {
        int frame[3] = {-1};
        int pages[5] = {
            5,7,2,5,3
        };

        int n;
        mainMenu();
        printf("\n Enter your choice ");
        scanf("%d",&n);
        switch(n) {
            case 1:
                FCFS(frame,pages);
                break;
            case 2:
                LRU(frame,pages);
                break;
            case 3:
                exit(0);
        }

    }
    return 0;
}

void mainMenu() {
    printf("\n***************************************\n");
    printf("\n1. FCFS");
    printf("\n2. LRU");
    printf("\n3. Exit");
    printf("\n***************************************\n");
}

void FCFS(int frame[3], int pages[5]) {
    int k = 0;
    printf("Pages\t\tF1\tF2\tF3\n");
    for(int i=0;i<5;i++) {
        int flag = 0;
        for(int j=0;j<3;j++) {
            if(pages[i]==frame[j]) {
                printf("%d\t\t%d\t%d\t%d\t Hit\n",pages[i], frame[0], frame[1], frame[2]);
                break;
            }else {
                k = k%3;
                frame[k++] = pages[i];
                printf("%d\t\t%d\t%d\t%d\t Fault\n", pages[i], frame[0], frame[1], frame[2]);
                break;
            }
        }
    }
}


void LRU(int frame[3], int pages[5]) {
    int k = 0;
    int least_recent = -1;
    printf("Pages\t\tF1\tF2\tF3\n");
    for(int i=0;i<5;i++) {
        int flag = 0;
        for(int j=0;j<3;j++) {
            if(pages[i]==frame[j]) {
                printf("%d\t\t%d\t%d\t%d\t Hit\n",pages[i], frame[0], frame[1], frame[2]);
                least_recent = j;
                
                break;
            }else {
                if(check(frame))
                    frame[k++] = pages[i];
                else
                    frame[least_recent] = pages[i];
                
                printf("%d\t\t%d\t%d\t%d\t Fault\n", pages[i], frame[0], frame[1], frame[2]);
                break;
            }
        }
    }
}

int check(int arr[3]){
    int count = 0;
    for(int i=0;i<3;i++){
        if(arr[i]!=0)
            count++;
    }
    if(count==3)
        return 0;
    else
        return 1;
}
