#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define maxn 500005

char s[maxn];
int pos[maxn], len[maxn];
int a, b, n;

void init(){
    memset(pos, 0, sizeof(pos));
    memset(len, 0, sizeof(len));
    int now=0, slen=0;
    for(int i=0;i<n;i++){
        if(s[i]==' '||i==n-1){
            len[now]=slen;
            if(i==n-1){
                len[now]++;
                pos[i]=now;
            }
            slen=0;
            now=i+1;
        }
        else{
            slen++;
            pos[i]=now;
        }
    }
}

int solve(int m){
    int v=0, now=0, i=0;
    while(i<n){
        v+=len[now]+1;
        i=now+m-1;
        if(i>=n)break;
        else if(s[i]==' '||s[i+1]==' '){
            now=i+1;
            if(s[i]!=' ')now=i+2;
        }
        else{
            now=pos[i];
        }
    }
    return v-1;
}

int main()
{
    gets(s);
    n=strlen(s);
    scanf("%d%d", &a, &b);
    init();
    for(int i=a;i<=b;i++){
        printf("%d\n", solve(i));
    }
    return 0;
}
