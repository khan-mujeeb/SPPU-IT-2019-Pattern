#include<stdio.h>
#include<stdlib.h>

void mainMenu();
void shortest_dstance(int request_queue[], int check[11], int head);
void SSTF(int request_queue[], int n, int head);
void SCAN(int request_queue[], int n, int head);
void bb(int arr[], int n);

int main() {

    
    

    while(1) {
       int size = 11;
       int request_queue[] = {
            4, 25, 45, 50, 52, 61, 67, 87, 89, 90
       };
       int check[size];
       int head = 50;

        int n;
        mainMenu();
        printf("\n Enter your choice ");
        scanf("%d",&n);
        switch(n) {
            case 1:
                SSTF(request_queue, size, head);
                break;
            case 2:
                SCAN(request_queue, size, head);
                break;
            case 3:
                exit(0);
        }

    }
    return 0;
}

void mainMenu() {
    printf("\n***************************************\n");
    printf("\n1. SSTF");
    printf("\n2. LRU");
    printf("\n3. Exit");
    printf("\n***************************************\n");
}

void SSTF(int request_queue[], int n, int head){

    printf("\n");
    int check[n];
    int index = -1;
    int dif = 0;
    
    int ditance = 0;
    for(int i=0;i<n;i++)
        if(request_queue[i]!=head)
            check[i] = -1;
        else
            check[i] = 1;
        
    int count = n;
    while(count>0) {
        int min = 999999;
        for(int i=0;i<n;i++) {
            dif = abs(request_queue[i] - head);
            if(check[i]==-1 && dif < min) {
                index = i;
                min = dif;
            }
        }
        check[index] = 1;
        ditance = ditance + abs(request_queue[index] - head);
        count--;
        printf("%d-->",head);
        head = request_queue[index];
    }
    printf("\nShortest seek distance is %d",ditance);
}


void SCAN(int request_queue[], int n, int head){

    printf("\n");
    int check[n];

    bb(request_queue, n);

    int init_head = head;
    int index = -1;
    int dif = 0;
    
    int ditance = 0;
    for(int i=0;i<n;i++)
        if(request_queue[i]!=head)
            check[i] = -1;
        else {
            check[i] = 1;
            index = i;
        }
            
    int i = index-1;
    while(i>=0) {
        int diff = abs(head - request_queue[i]);
        ditance+=diff;
        printf("%d-->",head);
        head = request_queue[i];
        i--;
    }        
    i = index+1;
    int distance2 = 0;
    while(i<n) {
        int diff = abs(head - request_queue[i]);
        distance2+=diff;
        printf("%d-->",head);
        // printf("\n %d - %d\n",head,request_queue[i]);
        head = request_queue[i];
        i++;
    }
    printf("\nShortest seek distance is %d", ditance + distance2);
}

void bb(int arr[], int n){
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i]<arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

