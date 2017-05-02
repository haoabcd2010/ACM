#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int f_i[30];//初始期望值
int temp_i[30];//等于上面的
int d_i[30];//期望递减值
int t_i[30];//跨池塘耗费时间
int n,h;

int spend[30][30];//在每一个池塘待的时间，spend[][0]是存在这个池塘钓鱼的期望值
int Diao(int k)
{
    memset(spend[k],0,sizeof(spend[k]));
    int i,res=0,time=h*60;
    for (i=1;i<=k;i++)
        temp_i[i]=f_i[i];
    for (i=1;i<k;i++)//路上的耗费都去掉
        time-=t_i[i]*5;
    while (time>0)
    {
        int max_=-999999,max_p;
        for (i=1;i<=k;i++)//每次找到最大的
        {
            if (temp_i[i]>max_)
            {
                max_=temp_i[i];
                max_p=i;
            }
        }
        if (max_>0)//还可以钓鱼
        {
            res+=max_;
            temp_i[max_p]-=d_i[max_p];
            spend[k][max_p]+=5;
            time-=5;
        }
        else
        {
            spend[k][1]+=time;
            break;
        }
    }
    spend[k][0]=res;//0位置放期望值
    return 0;
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
        scanf("%d",&h);
        int i;
        for (i=1;i<=n;i++)
            scanf("%d",&f_i[i]);
        for (i=1;i<=n;i++)
            scanf("%d",&d_i[i]);
        for (i=1;i<n;i++)
            scanf("%d",&t_i[i]);
        for (i=1;i<=n;i++)//在每一个池塘结束可钓最大值
            Diao(i);
        int ans=0,pos;
        for (i=1;i<=n;i++)
        {
            if (spend[i][0]>ans)
            {
                ans=spend[i][0];
                pos=i;
            }
            else if (spend[i][0]==ans)//等于，就要比谁在前面的池塘待的久
            {
                for (int j=1;j<=n;j++)
                {
                    if (spend[i][j]>spend[pos][j])
                    {
                        pos=i;
                        break;
                    }
                    else if (spend[i][j]<spend[pos][j])
                        break;
                }
            }
        }
        for (i=1;i<n;i++)
            printf("%d, ",spend[pos][i]);
        printf("%d\n",spend[pos][i]);
        printf("Number of fish expected: %d\n\n",ans);

    }
    return 0;
}


