#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 500

int n,m;
int G[MX][MX];

int main()
{
    scanf("%d%d",&n,&m);
    memset(G,0x3f,sizeof(G));
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a][b]=G[b][a]=c;
    }
    return 0;
}
