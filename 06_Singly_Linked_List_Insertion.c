#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*next;};

void display(struct Node*h){while(h){printf("%d ",h->data);h=h->next;}printf("\n");}
void insertBeg(struct Node**h,int x){struct Node*n=malloc(sizeof(*n));n->data=x;n->next=*h;*h=n;}
void insertEnd(struct Node**h,int x){struct Node*n=malloc(sizeof(*n));n->data=x;n->next=NULL;if(!*h){*h=n;return;}struct Node*p=*h;while(p->next)p=p->next;p->next=n;}
void insertPos(struct Node**h,int x,int pos){if(pos<=1){insertBeg(h,x);return;}struct Node*p=*h;for(int i=1;p&&i<pos-1;i++)p=p->next;if(!p){printf("Invalid position\n");return;}struct Node*n=malloc(sizeof(*n));n->data=x;n->next=p->next;p->next=n;}

int main(){struct Node*h=NULL;int c,x,p;do{printf("\n1.Begin 2.End 3.Position 4.Display 5.Exit\nChoice: ");scanf("%d",&c);if(c>=1&&c<=3){printf("Value: ");scanf("%d",&x);}if(c==1)insertBeg(&h,x);else if(c==2)insertEnd(&h,x);else if(c==3){printf("Position: ");scanf("%d",&p);insertPos(&h,x,p);}else if(c==4)display(h);}while(c!=5);return 0;}
