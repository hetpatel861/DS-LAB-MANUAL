#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*prev,*next;};

void display(struct Node*h){while(h){printf("%d ",h->data);h=h->next;}printf("\n");}
void insertPos(struct Node**h,int x,int pos){struct Node*n=malloc(sizeof(*n));n->data=x;n->prev=n->next=NULL;if(pos<=1){n->next=*h;if(*h)(*h)->prev=n;*h=n;return;}struct Node*p=*h;for(int i=1;p&&i<pos-1;i++)p=p->next;if(!p){printf("Invalid position\n");free(n);return;}n->next=p->next;n->prev=p;if(p->next)p->next->prev=n;p->next=n;}
void deletePos(struct Node**h,int pos){if(!*h){printf("Empty\n");return;}struct Node*p=*h;for(int i=1;p&&i<pos;i++)p=p->next;if(!p){printf("Invalid position\n");return;}if(p->prev)p->prev->next=p->next;else *h=p->next;if(p->next)p->next->prev=p->prev;free(p);}

int main(){struct Node*h=NULL;int c,x,p;do{printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");scanf("%d",&c);if(c==1){printf("Value & position: ");scanf("%d%d",&x,&p);insertPos(&h,x,p);}else if(c==2){printf("Position: ");scanf("%d",&p);deletePos(&h,p);}else if(c==3)display(h);}while(c!=4);return 0;}
