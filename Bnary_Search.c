#include<stdio.h>
int main()
            {
                  int a[50],n,i,ele,position;
                  printf("Enter the total number of elements\n");
                  scanf("%d",&n);
                  printf("Enter the elements\n");
                  for(i=0;i<n;i++)
                  scanf("%d",&a[i]);
                  printf("Enter the element that needs to be searched\n");
                  scanf("%d",&ele);
                  position=binarysearch(a,n,ele);
                  if(position==-1)
                  printf("Element %d not found",ele);
                  else
                  printf("Element %d found at  position:%d",ele,position+1);
            }

  int binarysearch(int a[],int n,int ele)
            {
                int low=0,up=n-1,mid;
                while(low<=up)
                    {
                        mid=(low+up)/2;
                        if(ele>a[mid])
                        low=mid+1;
                        else if(ele<a[mid])
                        up=mid-1;
                        else
                        return mid;
                    }
                return 1;
            }


