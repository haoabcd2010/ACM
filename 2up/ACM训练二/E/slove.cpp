#include <stdio.h>
#include <string.h>

const int maxn=500005;
const int maxnum=1000005;
int use[maxnum];//这个值的出现次数
int num[maxn];

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int i;
        for (i=1;i<=n;i++) scanf("%d",&num[i]);
        memset(use,0,sizeof(use));

        int l=1,r=1,sum=1;//用于遍历，sum记录不同数字个数
        int x=1,y=1,len=1;//用于记录答案

        use[num[1]]=1;
        while (r<n)
        {
            r++;
            if (!use[num[r]])
            {
                sum++;
                use[num[r]]=1;
            }
            else use[num[r]]++;
            while (sum>k)      //加了这个数不符合要求了,移动左边的
            {
                if (use[num[l]]==1) sum--;
                use[num[l]]--;
                l++;
            }
            if (r-l+1>len)
            {
                len=r-l+1;
                x=l;
                y=r;
            }
        }
        printf("%d %d\n",x,y);
    }

    return 0;
}



