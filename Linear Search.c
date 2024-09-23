#include<stdio.h>
int search(int *,int,int);
int main()
{
    int n,i,key,pos;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    
    }
    printf("Enter the key element:");
    scanf("%d",&key);
    pos=search(a,n,key);
    if(pos==-1)
        printf("Search is unsuccessful");
    else
        printf("Key is found at index %d",pos);
}

int search(int a[],int n,int key)
{
    int i,pos=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        return -1;
    }
    else
    {
        return pos;
    }
}
