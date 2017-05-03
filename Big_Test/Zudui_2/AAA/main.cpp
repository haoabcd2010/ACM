#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MEM 0x3f

int n,m;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int ta=0,tb=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ta+=x;
        }
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            tb+=x;
        }
        if (ta==tb)
            printf("Draw\n");
        else if(ta>tb)
            printf("Calem\n");
        else
            printf("Serena\n");
    }
    return 0;
}
