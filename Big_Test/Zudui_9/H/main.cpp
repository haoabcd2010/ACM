#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500005;
char s[maxn];
int len;
struct W{
    char c;
    int idx;
};
stack<W> sz;

int main()
{
    while(~scanf("%s", &s)){
        len=strlen(s);
        for(int i=0;i<len;i++){
            W w;
            w.c=s[i];
            w.idx=i;
            if(sz.empty()){
                sz.push(w);
            }
            else{
                W top=sz.top();
                if(top.c=='?'&&w.c=='?'){
                    continue;
                }
                else if(top.c=='?'&&w.c==')'){
                    s[top.idx]='(';sz.pop();continue;
                }
                else if(top.c=='('&&w.c=='?'){
                    s[w.idx]=')';sz.pop();continue;
                }
                else if(top.c=='('&&w.c==')'){
                    sz.pop();continue;
                }
                else{
                    sz.push(w);
                }
            }
        }
        while(!sz.empty()&&sz.top().c=='?')sz.pop();
        if(sz.empty()){
            printf("%s\n", s);
        }
        else{
            printf("Impossible\n");
        }
    }
    return 0;
}
