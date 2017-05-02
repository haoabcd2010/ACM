#include <stdio.h>

int count(int x)
{
    int n=x;
    int num=0;
    while (n)
    {
        num++;
        n/=10;
    }
    n=x;
    int zero=0;
    while (n)
    {
        int temp=n%10;
        if (temp==5)
            return (num-zero)*2-1;
        if (temp!=0)
            return (num-zero)*2;
        n/=10;
        zero++;//记录0的个数
    }
    return 0;
}

int add(int x)
{
    int r=1;
    while (x)
    {
        int temp = x%10;
        if (temp==0) r*=10;
        else break;
        x/=10;
    }
    return r;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int x=l;
        int h=count(x);
        int ans = l;
        while (1)
        {
            x+=add(x);
            if (x>r) break;
            if (count(x)<h)
            {
                h=count(x);
                ans=x;
            }
            if (h==1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
