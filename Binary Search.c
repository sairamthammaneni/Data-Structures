#include <stdio.h>
void search(int *,int ,int );
int main()
{
    int n,i,key;
    printf("Enter the list size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the list:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    search(a,n,key);
    return 0;
}

void search(int a[],int n,int key)
{
    int low,mid,high,count=0;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf("Search is succesful,Key is found at index %d",mid);
            count=1;
            break;
        }
        else if(key<mid)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(count==0)
        printf("Search is unsuccesful");
}
