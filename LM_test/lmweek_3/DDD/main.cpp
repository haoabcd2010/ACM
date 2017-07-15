#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
#define MX 1005
int x[MX];

int main()
{
    int n;
    while (scanf("%d",&n)&&n)
    {
        while (scanf("%d",&x[0])&&x[0])
        {
            x[1]=x[0];
            for (int i=2;i<=n;i++)
                scanf("%d",&x[i]);
            stack<int> sta;
            int j=1;
            int i=1;
            while (i<=n)
            {
                while (i<=n&&(sta.empty()||sta.top()!=x[j])) sta.push(i++);
                while (!sta.empty()&&sta.top()==x[j]) j++,sta.pop();
            }
            if (j==n+1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
