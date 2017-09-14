#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000005;

int n, s;
int ans[maxn];

inline int read(){
    int x=0, f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        n=read();
        s=read();
        memset(ans, 0, sizeof(ans));
        int len=n/2;
        if(n*9<s||(n!=1&&n%2==0&&s%2==1)||(n>1&&s<2)){
            printf("-1\n");continue;
        }
        else{
            for(int i=0;i<len;i++){
                if(s/2>=9){
                    ans[i]=9;
                    s-=2*9;
                }
                else{
                    if(s==1)break;
                    int t=s/2;
                    ans[i]=t;
                    s-=t*2;
                }
            }
        }
        for(int i=0;i<len;i++){
            printf("%d", ans[i]);
        }
        if(n%2==1)printf("%d", s);
        for(int i=len-1;i>=0;i--){
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
