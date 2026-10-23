#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*left,*right;};
struct Node*newNode(int x){struct Node*n=malloc(sizeof(*n));n->data=x;n->left=n->right=NULL;return n;}
struct Node*build(){int x;printf("Enter data (-1 for NULL): ");scanf("%d",&x);if(x==-1)return NULL;struct Node*r=newNode(x);r->left=build();r->right=build();return r;}
void inorder(struct Node*r){if(r){inorder(r->left);printf("%d ",r->data);inorder(r->right);}}
void preorder(struct Node*r){if(r){printf("%d ",r->data);preorder(r->left);preorder(r->right);}}
void postorder(struct Node*r){if(r){postorder(r->left);postorder(r->right);printf("%d ",r->data);}}
int main(){struct Node*r=build();printf("Inorder: ");inorder(r);printf("\nPreorder: ");preorder(r);printf("\nPostorder: ");postorder(r);printf("\n");return 0;}
