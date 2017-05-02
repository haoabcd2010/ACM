#include<stdio.h>
#include<math.h>
double a[100005];
int main()
{
 int n;

 scanf("%d",&n);
 for(int i=1;i<=n;i++) scanf("%lf",&a[i]);

 int s=1,e=2;
 double ans=-1;
 for(int i=2;i<=n;i++)
 {
  double tmp=fabs(a[i]-a[i-1]);
  if(ans<tmp)
  {
   s=i-1;
   e=i;
   ans=tmp;
  }
 }
 printf("%d %d\n",s,e);
 return 0;
}
