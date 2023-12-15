#include<stdio.h>
#include<stdlib.h>
struct Process{
    int arival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int check;
};

void mainMenu();
void sjf(struct Process p[4]);
int wt(int tat, int bt);
int tat(int ct, int at);

int main() {
    struct Process p[4];

    p[0].arival_time = 0;
    p[0].burst_time = 5;

    p[1].arival_time = 1;
    p[1].burst_time = 3;

    p[2].arival_time = 2;
    p[2].burst_time = 4;

    p[3].arival_time = 4;
    p[3].burst_time = 1;

    for(int i=0;i<4;i++){
        p[i].check = 0;
    }

    while(1) {
        int n;
        mainMenu();
        printf("\n Enter your choice ");
        scanf("%d",&n);
        switch(n) {
            case 1:
                sjf(p);
                break;
            case 2:
                break;
            case 3:
                exit(0);
        }

    }
    return 0;
}

void mainMenu() {
    printf("\n***************************************\n");
    printf("\n1. SJF");
    printf("\n2. RR");
    printf("\n3. Exit");
    printf("\n***************************************\n");
}

void sjf(struct Process p[4]) {
   
    int small = 99999;
    p[0].completion_time = p[0].burst_time;
    int ct = p[0].completion_time;
    p[0].turn_around_time = tat(p[0].completion_time, p[0].arival_time);
    p[0].waiting_time = wt(p[0].turn_around_time , p[0].burst_time);

    for(int i=1;i<4;i++) {
        int bt =4;
        for(int j=1;j<4;j++) {
            if(p[j].burst_time<=bt && p[j].check==0){
                bt = p[j].burst_time;
                small = j;
            }
        }
        p[small].completion_time = ct+p[small].burst_time;
        ct = p[small].completion_time;
        p[small].check = 1;
        p[small].turn_around_time = tat(p[small].completion_time, p[small].arival_time);
        p[small].waiting_time = wt(p[small].turn_around_time , p[small].burst_time);
    }
    
    printf("P  AT BT CT TAT WT\n");
    for(int i=0;i<4;i++) {
      
        printf("P%d  %d  %d  %d  %d  %d \n", i+1, p[i].arival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time );
    }

}

int wt(int tat, int bt){
    return tat - bt;
}

int tat(int ct, int at) {
    return ct - at;
}