#include <stdio.h>
#include <string.h>

const int maxn=500005;
const int maxnum=1000005;
int use[maxnum];//���ֵ�ĳ��ִ���
int num[maxn];

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int i;
        for (i=1;i<=n;i++) scanf("%d",&num[i]);
        memset(use,0,sizeof(use));

        int l=1,r=1,sum=1;//���ڱ�����sum��¼��ͬ���ָ���
        int x=1,y=1,len=1;//���ڼ�¼��

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
            while (sum>k)      //���������������Ҫ����,�ƶ���ߵ�
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



