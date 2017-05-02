#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=110;
int dp[maxn][maxn];
char a[maxn],b[maxn];
int ans[maxn];
int main()
{
    while (cin>>a>>b)
    {
        int i,j,k,n,len;
        n=strlen(a);
        memset(dp,0,sizeof(dp));
        //Ϊ�����㣬һ����ʱ����Ҫ�ı���ܵõ���Ӧ��ĸ��
        //��Ϊ��һ�α����º����ַ���ԭ����ȵ�ֵ�͸ı��ˡ�
        for(i=0;i<n;i++)dp[i][i]=1;

        for(len=2;len<=n;len++)//ö�ٳ���
        {
            for(i=0;i<n-len+1;i++)//ö�����
            {
                j=i+len-1;//�յ�
                //cout<<i<<" "<<j<<endl;
                dp[i][j]=dp[i+1][j]+1;//����ֻ�бȽϵ���b[i]=b[k]�����Բ�����dp[i][j]=dp[i][j-1]+1
                for(k=i+1;k<=j;k++)//ö�ٷָ��
                {
                    if(b[i]==b[k])
                    {
                        //cout<<i<<" "<<k<<endl;
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                    }
                }
            }
        }
        for(i=0;i<n;i++)
            ans[i]=dp[0][i];
        for(i=0;i<n;i++)
        {
            //���¼������ַ������ַ���ͬ�ĵ㡣
            if(a[i]==b[i])
            {
                if(i==0)ans[i]=0;
                else ans[i]=ans[i-1];
            }
            else
            {
                for(j=0;j<i;j++)
                ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
            }
        }
        cout<<ans[n-1]<<endl;
    }
    return 0;
}
