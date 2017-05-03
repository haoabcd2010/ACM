#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn=20010;

struct Man{
    int t, idx;
}man[maxn];

bool cmp(Man a, Man b){
    return a.t<b.t;
}

int T, n, m, cnt, flag[maxn], num;
int hh, mm, ss;
int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%d:%d:%d", &hh, &mm, &ss);
            man[i].idx=i+1;
            man[i].t=hh*60*60+mm*60+ss;
        }
        memset(flag, 0, sizeof(flag));
        sort(man, man+n, cmp);
        num=0;
        int now=man[0].t;
        flag[num++]=man[0].idx;
        cnt=1;
        for(int i=1;i<n;i++){
            if(man[i].t-now>=m){
                flag[num++]=man[i].idx;
                now=man[i].t;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        sort(flag, flag+num);
        for(int i=0;i<num;i++){
            printf("%d", flag[i]);
            if(i==num-1)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
