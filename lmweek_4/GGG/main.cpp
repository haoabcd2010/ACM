#include <iostream>
#include <stdio.h>
using namespace std;

int slove(int x)
{
    int num[10];
    int ok=1;
    int k=0;
    while (x)
    {
        num[k++]=x%10;
        if (num[k-1]==4) ok=0;
        if (k>1&&num[k-1]==6&&num[k-2]==2) ok=0;
        x/=10;
    }
    return ok;
}

int main()
{
    int l,r;
    while (scanf("%d%d",&l,&r)&&(l+r))
    {
        int ans = 0;
        for (int i=l;i<=r;i++)
            if (slove(i)) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
