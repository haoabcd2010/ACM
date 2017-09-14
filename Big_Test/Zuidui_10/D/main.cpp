#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1000005;
int data[maxn], res[maxn];
int n, t;

int main()
{
    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &data[i]);
        }
        data[n]=data[n-1];
        int h,d,th,td,go,cnt;
        h=d=td=th=go=0;
        for(int i=1;i<=n;i++){
            if(data[i]==data[i-1]){     // go
                if(go==1){
                    td=min(td, th);
                    d=max(d, td);
                }
                else if(go==-1){
                    th=min(th, td);
                    h=max(h, th);
                }
                th=td=go=0;continue;
            }
            if(data[i]>data[i-1]){      //up
                if(go==-1){     //if last is down
                    th=min(td, th);
                    h=max(h, th);
                    th=0;
                }
                th++;
                go=1;
            }
            else{                       //down
                if(go==1){      //if last is up
                    td=min(th, td);
                    d=max(d, td);
                    td=0;
                }
                td++;
                go=-1;
            }
        }
        printf("%d %d\n", h, d);
    }
    return 0;
}
