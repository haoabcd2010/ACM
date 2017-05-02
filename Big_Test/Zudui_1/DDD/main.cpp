#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x3fffffff
#define MX  205

int n;
int d[MX];
int e[MX];
int dp[MX][MX];

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&e[i]);
        e[0]=0;e[n+1]=0;
        for (int i=1;i<=n;i++)
            dp[i][i]=d[i]+e[i-1]+e[i+1];
        for (int l=2;l<=n;l++)  //����
        {
            for (int i=1;i+l-1<=n;i++)
            {
                int r = i+l-1;
                dp[i][r]=INF;
                for (int k=i;k<=r;k++)   //ö�����Ҫɱ����
                    dp[i][r]=min(dp[i][r],dp[i][k-1]+dp[k+1][r]+d[k]+e[i-1]+e[r+1]);
                //����������ʵ� dp [i][i-1] ʱ���ض��� 0 �����Բ��ش���Խ�����
            }
        }
        printf("Case #%d: %d\n",cnt,dp[1][n]);
    }
    return 0;
}
