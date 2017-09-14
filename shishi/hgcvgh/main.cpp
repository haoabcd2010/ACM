/*
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define MX 10000005
bool prim[MX];
vector<int>ans;

int main()
{
    int n;
    scanf("%d",&n);
    prim[0]=1; prim[1]=0;

    for (int i=2;i<=n;i++)
    {
        if (!prim[i])
        {
            ans.push_back(i);
            for (int j=2*i;j<=n;j+=i)
                prim[j]=1;
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d : %d\n",i+1,ans[i]);
    return 0;
}
*/
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int N = 100000000;
int prime[N];
int num_prime = 0;
int isNotPrime[N] = {1, 1};

int main()
{
    for(int i = 2 ; i < N ; i ++)
    {
        if(! isNotPrime[i])
        {
            prime[num_prime ++]=i;
        }
        for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if( !(i % prime[j] ) ) break;
        }
    }
    printf("%d\n",num_prime);
    return 0;
}
