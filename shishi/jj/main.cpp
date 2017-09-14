#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+5;
int n, k;
int data[maxn];

int main()
{
    while(~scanf("%d%d", &n, &k)){
        for(int i=0;i<n;i++)scanf("%d", &data[i]);
        double p=(k-1)*1.0/k;
        int ans=0;
        for(int i=1;i<n;i++){
            if(data[i]==data[i-1])continue;
            else ans++;
        }
        printf("%.9lf\n", ans*p);
    }
    return 0;
}
