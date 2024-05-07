#include<stdio.h>
void selectionsort(int [],int );
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
    selectionsort(a,n);
    printf("The sorted list are : ");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    
    }

}

void selectionsort(int a[],int n)
{
    int i,j,minpos,temp;
    for(i=0;i<(n-1);i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[minpos])
            {
                minpos=j;
            }
        }
        temp=a[i];
        a[i]=a[minpos];
        a[minpos]=temp;
        
    }
    
}
