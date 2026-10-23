#include <stdio.h>
#define MAX 100
int main() {
    int s[MAX], top=-1, choice, x, pos, i;
    do {
        printf("\n1.PUSH 2.POP 3.PEEP 4.CHANGE 5.DISPLAY 6.EXIT\nChoice: ");
        scanf("%d",&choice);
        if(choice==1) {
            if(top==MAX-1) printf("Stack Overflow\n");
            else { printf("Value: "); scanf("%d",&x); s[++top]=x; }
        } else if(choice==2) {
            if(top==-1) printf("Stack Underflow\n");
            else printf("Popped: %d\n",s[top--]);
        } else if(choice==3) {
            if(top==-1) printf("Stack Empty\n");
            else printf("Top: %d\n",s[top]);
        } else if(choice==4) {
            printf("Position from top (1-%d) and value: ",top+1);
            scanf("%d%d",&pos,&x);
            if(pos<1 || pos>top+1) printf("Invalid position\n");
            else s[top-pos+1]=x;
        } else if(choice==5) {
            if(top==-1) printf("Stack Empty\n");
            else { for(i=top;i>=0;i--) printf("%d ",s[i]); printf("\n"); }
        }
    } while(choice!=6);
    return 0;
}
