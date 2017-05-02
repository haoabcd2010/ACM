#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        priority_queue<int> Q;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        for (int i=0;i<n;i++)
        {
            int x = Q.top();Q.pop();
            printf("%d ",x);
        }

    }
    return 0;
}
