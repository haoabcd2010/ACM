#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define MX 500005

char ss[MX];
bool vis[MX];

int main()
{
    while (scanf("%s",ss)!=EOF)
    {
        int len = strlen(ss);
        memset(vis,0,sizeof(vis));
        vector<int> wen;
        stack<int> zuo;
        for (int i=0;i<len;i++)
        {
            if (ss[i]=='?')
                wen.push_back(i);
            else if (ss[i]=='(')
            {
                zuo.push(i);
            }
            else if (ss[i]==')')
            {
                if (zuo.size()>0)
                {
                    int pos = zuo.top(); zuo.pop();
                    vis[pos]=1;vis[i]=1;
                }
            }
        }
        int ok=1;
        int l = 0,r=wen.size()-1;

        for (int i=0;i<len;i++)
        {
            if (vis[i]==0)
            {
                if (ss[i]=='(')
                {

                    if (l<=r&&wen[r]>i)
                    {
                        ss[wen[r]]=')';
                        vis[wen[r]]=1;
                        r--;
                    }
                    else ok=0;
                }
                else if (ss[i]==')')
                {
                    if (l<=r&&wen[l]<i)
                    {
                        ss[wen[l]]='(';
                        vis[wen[l]]=1;
                        l++;
                    }
                    else ok=0;
                }
            }
            if (!ok) break;
        }
        if (l<=r)
        {
            if ((l-r)%2==0) ok=0;
            else
            {
                while (l<r)
                {
                    ss[wen[l]]='(';
                    ss[wen[r]]=')';
                    l++,r--;
                }
            }
        }
        if (!ok)
            printf("Impossible\n");
        else
            printf("%s\n",ss);
    }
    return 0;
}
