#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=100010,Mod=1000000007;
long long dp[N],sum[N],ans;int T,n;
long long Inv(long long x){
    return x==1?1:(Mod-Mod/x)*Inv(Mod%x)%Mod;
}
long long i2,i6;
int main(){
    sum[0]=1;dp[0]=1;
    sum[1]=2;dp[1]=1;
    i2=Inv(2);i6=Inv(6);
    for(int i=2;i<N;i++){
        dp[i]=dp[i-1]*(dp[i-1]+1)%Mod*i2%Mod;
        (dp[i]+=dp[i-1]*sum[i-2]%Mod)%=Mod;
        sum[i]=(sum[i-1]+dp[i])%Mod;
    }

    while(scanf("%d",&n)!=EOF&&n){
        if(n==1){printf("1\n");continue;}
        else if(n%2==1){
            ans=sum[n/2-1]*(dp[n/2]*(dp[n/2]+1)%Mod*i2%Mod)%Mod;
            ans+=dp[n/2]*(dp[n/2]-1+Mod)%Mod*(dp[n/2]-2+Mod)%Mod*i6%Mod;
            ans=((ans+dp[n/2]*(dp[n/2]-1+Mod)%Mod)%Mod+dp[n/2])%Mod;
        }
        else ans=dp[n/2]*(dp[n/2]+1)%Mod*i2%Mod;
        printf("%lld\n",ans);
    }
    return 0;
}
