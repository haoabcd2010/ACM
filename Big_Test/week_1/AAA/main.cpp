/*
POJ 2096
����DP
writed by kuangbin

dp������
���ŵ������
���⣺�����⿴��Ŀȷʵ�Ƚ��ѵ���n��s��Ҫ�Ұ�������ҵ���
   һ�������s����ϵͳ�������n��bug
   ĳ��һ�췢��һ��bug,���bug����һ����ϵͳ������һ������
   ÿ��bug����ĳ����ϵͳ�ĸ�����1/s,����ĳ�ַ���ĸ�����1/n
   �ʷ���n��bug,ÿ����ϵͳ������bug��������������

��⣺
         dp[i][j]��ʾ�Ѿ��ҵ�i��bug,j��ϵͳ��bug���ﵽĿ��״̬������������
         dp[n][s]=0;Ҫ��Ĵ���dp[0][0];
         dp[i][j]����ת������������״̬:
              dp[i][j],����һ��bug�����Ѿ� �е�i�������j��ϵͳ������Ϊ(i/n)*(j/s);
              dp[i][j+1],����һ��bug�������еķ��࣬���������е�ϵͳ.����Ϊ (i/n)*(1-j/s);
              dp[i+1][j],����һ��bug�������е�ϵͳ�����������еķ���,����Ϊ (1-i/n)*(j/s);
              dp[i+1][j+1],����һ��bug���������е�ϵͳ�����������еķ���,����Ϊ (1-i/n)*(1-j/s);
        �����õ�ת�Ʒ���
*/


#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 1010

double dp[MAXN][MAXN];

int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[n][s]=0.0;
        for (int i=n;i>=0;i--)
        {
            for (int j=s;j>=0;j--)
            {
                if (i==n&&j==s) continue;
                dp[i][j]=(n*s+dp[i+1][j]*(n-i)*j+dp[i][j+1]*i*(s-j)+dp[i+1][j+1]*(n-i)*(s-j))/(n*s-i*j);//ע���������͵���ʽת��
            }
        }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
