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
        //为处理方便，一个的时候都需要改变才能得到对应字母。
        //因为当一段被更新后，两字符串原本相等的值就改变了。
        for(i=0;i<n;i++)dp[i][i]=1;

        for(len=2;len<=n;len++)//枚举长度
        {
            for(i=0;i<n-len+1;i++)//枚举起点
            {
                j=i+len-1;//终点
                //cout<<i<<" "<<j<<endl;
                dp[i][j]=dp[i+1][j]+1;//由于只有比较的是b[i]=b[k]，所以不能用dp[i][j]=dp[i][j-1]+1
                for(k=i+1;k<=j;k++)//枚举分割点
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
            //重新计算两字符串中字符相同的点。
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
