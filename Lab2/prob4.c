#include <stdio.h>

int a[10] = {1, 6, 2, 4, 50, 21, 11, 23, 96, 69};
int b[10];

void merge(int low, int mid, int high) 
{
   int l1 = low;
   int l2 = mid + 1;
   int i = 0;

   while (l1 <= mid && l2 <= high) {
      if(a[l1] <= a[l2])
         b[i++] = a[l1++];
      else
         b[i++] = a[l2++];
   }
   
   while (l1 <= mid)    
      b[i++] = a[l1++];

   while (l2 <= high)   
      b[i++] = a[l2++];

   for (i = low; i <= high; i++)
      a[i] = b[i];
}

void merge_sort(int low, int high) {
   if(low < high) 
   {
      int middle = (low + high) / 2;
      merge_sort(low, middle);
      merge_sort(middle + 1, high);
      merge(low, middle, high);
   } 
   else  
      return;
}

int main() { 
   int i;
   int n = 10;
   merge_sort(0, n);
   for(i = 0; i <= n; i++)
      printf("%d ", a[i]);
}