#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=500005;

int n, k;
int data[maxn], up[maxn], x;

int main()
{
    while(~scanf("%d%d", &n, &k)){
        memset(up, 0, sizeof(up));
        int now=1;
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            if(x<0)data[i]=-1;
            else data[i]=1;
            if(i<k)now*=data[i];
        }
        int ans=0, sum=0;
        if(now<0){
            up[k-1]=1;
            ans++;
            sum++;
        }
        int rem=0;
        for(int i=k;i<n;i++){
            now*=data[i];
            now/=data[i-k];
            sum-=up[i-k];
            if(rem&&up[i-k]==1){
                sum++;
                rem=0;
            }
            if(now<0){
                if(sum==0){
                    up[i]=1;
                    ans++;
                    sum++;
                }
                else{
                    sum--;
                    rem=1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
