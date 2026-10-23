#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*left,*right;};
struct Node*insert(struct Node*r,int x){if(!r){r=malloc(sizeof(*r));r->data=x;r->left=r->right=NULL;return r;}if(x<r->data)r->left=insert(r->left,x);else if(x>r->data)r->right=insert(r->right,x);return r;}
void inorder(struct Node*r){if(r){inorder(r->left);printf("%d ",r->data);inorder(r->right);}}
int main(){struct Node*r=NULL;int n,x;printf("Number of nodes: ");scanf("%d",&n);printf("Enter values: ");for(int i=0;i<n;i++){scanf("%d",&x);r=insert(r,x);}printf("BST inorder: ");inorder(r);printf("\n");return 0;}
