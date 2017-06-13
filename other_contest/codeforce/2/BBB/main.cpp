#include <bits/stdc++.h>
using namespace std;
#define MX 1005

int a[MX];
int b[MX];

int num[MX]; // zhi wei i zai pos

int main()
{
    int n;
    scanf("%d",&n);
    int x1,x2,dis;
    memset(num,0,sizeof(num));
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (num[a[i]]==0) num[a[i]]=i;
        else x2=i;
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);

    for (int i=1;i<=n;i++)
        if (num[i]==0)
        dis=i; //dis 没出现过

    x1 = num[a[x2]];

    if(a[x1]==b[x1])
        a[x2]=dis;
    else if (a[x2]==b[x2])
        a[x1]=dis;
    else
    {
        if(b[x1]==dis)
            a[x1]=dis;
        else
            a[x2]=dis;
    }

    for (int i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);

    return 0;
}
