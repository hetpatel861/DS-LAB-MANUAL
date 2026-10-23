#include <stdio.h>
#define MAX 100
int main(){
    int q[MAX], front=0, rear=-1, choice, x, i;
    do{
        printf("\n1.INSERT 2.DELETE 3.DISPLAY 4.EXIT\nChoice: "); scanf("%d",&choice);
        if(choice==1){
            if(rear==MAX-1) printf("Queue Full\n");
            else { printf("Value: "); scanf("%d",&x); q[++rear]=x; }
        } else if(choice==2){
            if(front>rear) printf("Queue Empty\n");
            else printf("Deleted: %d\n",q[front++]);
        } else if(choice==3){
            if(front>rear) printf("Queue Empty\n");
            else { for(i=front;i<=rear;i++) printf("%d ",q[i]); printf("\n"); }
        }
        if(front>rear){front=0;rear=-1;}
    }while(choice!=4);
    return 0;
}
