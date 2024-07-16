#include<stdio.h>
int linear_search(int*, int, int);

int main()
{
   int a[10], search, i, n, position;

   printf("Enter the number of elements in array\n");
   scanf("%d",&n);

   printf("Enter %d numbers\n", n);

   for ( i = 0 ; i< n ; i++ )
      scanf("%d",&a[i]);

   printf("Enter the number to search\n");
   scanf("%d",&search);

   position = linear_search(a, n, search);

   if ( position == 1 )
       printf("%d is  not present  .\n", search);
   else

      printf("%d is present in array at location %d.\n", search,position+1);

   return 0;
}

int linear_search(int *pointer, int n, int find)
{
   int x;

   for ( x = 0 ; x < n ; x++ )
   {
      if ( *(pointer+x) == find )
         return x;
   }

   return 1;
}


