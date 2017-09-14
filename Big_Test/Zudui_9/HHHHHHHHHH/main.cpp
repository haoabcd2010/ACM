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

bool cmp(W ca, W cb){
    return ca.idx<cb.idx;
}

stack<W> S;
vector<W> V;

int main()
{
    while(~scanf("%s", s)){
        len=strlen(s);
        if(len%2){
            printf("Impossible\n");continue;
        }
        for(int i=0;i<len;i++){
            W w;
            w.c=s[i];
            w.idx=i;
            if(s[i]=='?'){
                V.push_back(w);
            }
            else{
                if(!S.empty()){
                    W top=S.top();
                    if(top.c=='('&&w.c==')')S.pop();
                    else S.push(w);
                }
                else{
                    S.push(w);
                }
            }
        }
        while(!S.empty()){
            W w=S.top();
            S.pop();
            V.push_back(w);
        }
        sort(V.begin(), V.end(), cmp);
        for(int i=0;i<V.size();i++){
            W w=V[i];
            if(!S.empty()){
                W top=S.top();
                if(top.c=='?'&&w.c==')'){
                    s[top.idx]='(';
                    S.pop();
                }
                else if(top.c=='('&&w.c=='?'){
                    s[w.idx]=')';
                    S.pop();
                }
                else if(top.c=='?'&&w.c=='?'){
                    s[top.idx]='(';
                    s[w.idx]=')';
                    S.pop();
                }
                else S.push(w);
            }
            else{
                S.push(w);
            }
        }
        if(S.empty()){
            printf("%s\n", s);
        }
        else printf("Impossible\n");
        V.clear();
        while(!S.empty())S.pop();
    }
    return 0;
}
