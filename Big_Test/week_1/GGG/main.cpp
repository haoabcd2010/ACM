#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = (1<<20)+10;
int n;
double p[25];
double dp[MAXN];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%lf",&p[i]);

        int mmm = (1<<n)-1;     //������Ϊ n �� 1
        dp[mmm]=0;
        for (int i=mmm-1;i>=0;i--)  //���������������
        {
            double all_p=0;
            dp[i]=1;
            for (int j=0;j<n;j++)
            {
                if ( (i&(1<<j))==0 )    //�� j �ֿ�Ƭû��
                {
                    dp[i]+=p[j]*dp[i+(1<<j)];   //dp [i+(1<<j)] �϶�����ֵ��
                    all_p+=p[j];
                }
            }
            dp[i]/=all_p;
        }
        printf("%lf\n",dp[0]);
    }
}




