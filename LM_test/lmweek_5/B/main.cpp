#include <bits/stdc++.h>
using namespace std;
#define MX 100005
#define has 100000
int n;
int f[MX*2];

int find_(int x)
{
    if (x!=f[x])
        f[x]=find_(f[x]);
    return f[x];
}
int join(int a,int b)
{
    int x=find_(a),y=find_(b);
    if (x!=y)
        f[x]=f[y];
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) f[i]=i;
        for (int i=has+1;i<=has+n;i++) f[i]=i;
        for (int i=1;i<=n;i++)
        {
            int x,k;
            scanf("%d%d",&x,&k);
            if (k==1)
            {
                join(i,x);
                join(has+i,has+x);
            }
            if (k==2)
            {
                join(i,has+x);
                join(has+i,x);
            }
        }
        int ok=1;
        for (int i=1;i<=n;i++)
        {
            if (find_(i)==find_(has+i))
            {
                ok=0;
                break;
            }
        }
        if (ok)
            printf("Time to show my power\n");
        else
            printf("One face meng bi\n");
    }
    return 0;
}
