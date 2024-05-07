#include<stdio.h>
void insertionsort(int [],int );
int main()
{
    int i,n;
    printf("Enter the size n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printf("The sorted list are : ");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    
    }
}


void insertionsort(int a[],int n)
{
    int i,j,item;
    for(i=1;i<=(n-1);i++)
    {
        item=a[i];
        for(j=i-1;j>=0 && a[j]>item;j--)
        {
            a[j+1]=a[j];
        
        }
        a[j+1]=item;    
    }
}
