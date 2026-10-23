#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX], n, i, pos, val, key, found = -1, choice;
    printf("Enter size: "); scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    do {
        printf("\n1.Insert  2.Delete  3.Search  4.Traverse  5.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Position(1-%d) and value: ", n+1);
            scanf("%d%d",&pos,&val);
            if(pos<1 || pos>n+1 || n==MAX) printf("Invalid position/full array\n");
            else {
                for(i=n;i>=pos;i--) a[i]=a[i-1];
                a[pos-1]=val; n++;
            }
        } else if(choice==2) {
            printf("Position(1-%d): ", n);
            scanf("%d",&pos);
            if(pos<1 || pos>n) printf("Invalid position\n");
            else {
                for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
                n--;
            }
        } else if(choice==3) {
            printf("Search value: "); scanf("%d",&key);
            found=-1;
            for(i=0;i<n;i++) if(a[i]==key){found=i;break;}
            if(found==-1) printf("Not found\n");
            else printf("Found at position %d\n",found+1);
        } else if(choice==4) {
            printf("Array: ");
            for(i=0;i<n;i++) printf("%d ",a[i]);
            printf("\n");
        }
    } while(choice!=5);
    return 0;
}
