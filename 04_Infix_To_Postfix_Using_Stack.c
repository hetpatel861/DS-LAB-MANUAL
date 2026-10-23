#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char st[MAX]; int top=-1;
int prec(char c){ if(c=='^')return 3; if(c=='*'||c=='/'||c=='%')return 2; if(c=='+'||c=='-')return 1; return 0; }

int main(){
    char in[MAX], out[MAX], c; int i,j=0;
    printf("Enter infix expression: "); scanf("%s",in);
    for(i=0;in[i]!='\0';i++){
        c=in[i];
        if(isalnum(c)) out[j++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){
            while(top>=0 && st[top]!='(') out[j++]=st[top--];
            if(top>=0) top--;
        } else {
            while(top>=0 && st[top]!='(' && prec(st[top])>=prec(c)) out[j++]=st[top--];
            st[++top]=c;
        }
    }
    while(top>=0) out[j++]=st[top--];
    out[j]='\0';
    printf("Postfix: %s\n",out);
    return 0;
}
