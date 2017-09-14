#include "cstdio"
#include "cstring"
#include "algorithm"

struct city
{
    int d;
    int v;
};
city C[1004];
int mm[1004];
bool cmp(city x, city y)
{
    return x.d<y.d;
}
int main()
{
    int n,h;
    while (scanf ("%d%d",&n,&h) != EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf ("%d%d",&C[i].d,&C[i].v);
        }
        memset(mm,0,sizeof(mm));
        int sum=0,ma,in,k=0;
        std::sort(C,C+n,cmp);
        for (int i=0;i<n;i++)
        {
            in=-1;
            ma=0;
            for (int j=0;j<n;j++)
            {
                if (C[j].d + i + 1 <= h)
                {
                    if (ma <= C[j].v)
                    {
                         in = j;
                         ma = C[j].v;
                    }
                }
            }
            sum += ma;
            if (in != -1) {C[in].d = h;  mm[i]=ma;}
        }

        int u=0;
        for (int i=0;i<n;i++)
        {
            ma = 0;
            u += mm[i];
            for (int j=0;j<n;j++)
            {
                if (C[j].d + i + 1<= h)
                {
                    ma = std::max(ma,C[j].v);
                }
            }
            if (u + ma > sum)
            {
                sum = u + ma;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
