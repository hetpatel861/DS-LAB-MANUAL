#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*next;};

void display(struct Node*h){while(h){printf("%d ",h->data);h=h->next;}printf("\n");}
void deleteBeg(struct Node**h){if(!*h){printf("Empty\n");return;}struct Node*t=*h;*h=t->next;free(t);}
void deleteEnd(struct Node**h){if(!*h){printf("Empty\n");return;}if(!(*h)->next){free(*h);*h=NULL;return;}struct Node*p=*h;while(p->next->next)p=p->next;free(p->next);p->next=NULL;}
void deletePos(struct Node**h,int pos){if(pos<=1){deleteBeg(h);return;}struct Node*p=*h;for(int i=1;p&&p->next&&i<pos-1;i++)p=p->next;if(!p||!p->next){printf("Invalid position\n");return;}struct Node*t=p->next;p->next=t->next;free(t);}

int main(){struct Node*h=NULL,*n;int nval,i,c,p;printf("Enter number of initial nodes: ");scanf("%d",&nval);for(i=0;i<nval;i++){n=malloc(sizeof(*n));scanf("%d",&n->data);n->next=NULL;if(!h)h=n;else{struct Node*q=h;while(q->next)q=q->next;q->next=n;}}do{printf("\n1.Delete Beginning 2.Delete End 3.Delete Position 4.Display 5.Exit\nChoice: ");scanf("%d",&c);if(c==1)deleteBeg(&h);else if(c==2)deleteEnd(&h);else if(c==3){printf("Position: ");scanf("%d",&p);deletePos(&h,p);}else if(c==4)display(h);}while(c!=5);return 0;}
