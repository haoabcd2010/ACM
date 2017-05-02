#include <stdio.h>
 long c;
 int N=5;
 long A[5]; //long A[N];

 long P(long l, long r)
 {
  long x=A[l],
       i=l-1,
       j=r+1,
       t;
  while(1)
  {
   do{--j; ++c;}
   while(A[j]>x);//直到小于或等于 A[l]

   do{++i; ++c;}
   while(A[i]<x);//直到大于或等于 A[l]

   if(i<j)// A[i] 和 A[j] 交换
   {
    t=A[i];
    A[i]=A[j];
    A[j]=t;
   }
   else return j;
  }
 }

 void Q(long l, long r)
 {
  long n;
  if(l<r)
  {
   n=P(l,r);
   Q(l,n);
   Q(n+1,r);
  }
 }

 int main(void)
 {
  c=0;
  for(long i=0; i<N; ++i)
   scanf("%ld", &A[i]);
  Q(0,N-1);
  if(c<=(N*N+3*N-4)/2)
    printf("Beutiful Vasilisa");
  else printf("Immortal Koshcei");
  return 0;
 }
