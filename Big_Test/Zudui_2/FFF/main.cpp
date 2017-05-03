#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MEM 0x3f
#define MX 42
struct Node
{
    char mp[MX][MX];
}star;
int n,m;

int bfs()
{
}

int main()
{
    printf("%d",ans);
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%s",star.mp[i]);
        }
        bfs();
    }
    return 0;
}
