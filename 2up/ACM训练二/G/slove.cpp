#include <stdio.h>

int abs_(int a)
{
    if (a>0)
        return a;
    return -a;
}

int min_(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int x1,y1,x2,y2;
    while (scanf("%d%d",&x1,&y1)!=EOF)
    {
        scanf("%d%d",&x2,&y2);
        int s_x,s_y,m_s;
        int ans=0;

        s_x=abs_(x2-x1);
        s_y=abs_(y2-y1);
        m_s=min_(s_x,s_y);

        ans+=m_s;
        ans+=abs_(s_x-s_y);
        printf("%d\n",ans);
    }
    return 0;
}
