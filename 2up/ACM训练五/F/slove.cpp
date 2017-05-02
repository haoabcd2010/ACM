/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int dp[15][10];
//dp[i][j]表示考虑i位的数中，最高为j的windy数
void Init()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=9;i++)
		dp[1][i]=1;
	for(int i=2;i<=10;i++)
    {
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
				if(abs(j-k)>=2)
					dp[i][j]+=dp[i-1][k];
		}
	}
}

int slove(int n)
{
	int len=0,bit[15];
	while(n)
    {
		bit[++len]=n%10;
		n/=10;
	}
	bit[len+1]=0;
	int ans=0;
	//先把长度为1至len-1计入
	for(int i=1;i<len;i++)
		for(int j=1;j<10;j++)
	    	ans+=dp[i][j];
	//确定最高位
	for(int j=1;j<bit[len];j++)
		ans+=dp[len][j];
	for(int i=len-1;i;i--)
    {
		for(int j=0;j<bit[i];j++)
			if(abs(j-bit[i+1])>=2)
				ans+=dp[i][j];
		//如果高位已经出现非法，直接退出
		if(abs(bit[i]-bit[i+1])<2)
			break;
	}
	return ans;
}
int main()
{
	Init();
	int l,r;
	while(scanf("%d%d",&l,&r)!=EOF)
		printf("%d\n",slove(r+1)-slove(l));
	return 0;
}
*/

#include <stdio.h>

//dp[i][j] i 位，最高位是 j 的数的windy数
int dp[12][10];

int main()
{
    Init();
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {

    }
    return 0;
}


